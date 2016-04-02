#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define NB_ITER 10

int father_process(pid_t , int [2], int [2]);
int child_process(int [2], int [2]);

int main (int argc, char* argv[])
{
	int pongPipe[2];
	int pingPipe[2];
	pid_t child;
	// initialise le pipe.
	pipe(pongPipe);
	pipe(pingPipe);
	// divise le processus.
	child = fork();
	if(child == -1){
		// décris l'erreur.
		perror("Fork error");
		// ferme les descripteur ouvert.
		close(pingPipe[1]);		close(pongPipe[0]);
		close(pongPipe[1]);		close(pingPipe[0]);
		// arrêt suite à une erreur.
		exit(EXIT_FAILURE);
	}

	if(child == 0){
		// lance le code du fils.
		_exit(child_process(pongPipe, pingPipe));
	}
	else{
		// lance le code du père.
		exit(father_process(child, pongPipe, pingPipe));
	}
}

int father_process (pid_t child, int pongPipe[2], int pingPipe[2]){
	FILE* in,* out;
	char buffer[50];
	int	number = 1,i;

	close(pongPipe[1]);
	close(pingPipe[0]);

	in = fdopen(pongPipe[0],"r");
	out = fdopen(pingPipe[1],"w");

	fprintf(out,"%d\n",number);
	fflush(out);
		
	for(i=0;i<NB_ITER;i++){
		printf("ping waiting...\n");
					
		while(fgets(buffer,sizeof(buffer), in) == NULL);

		number = atoi(buffer);

		printf("ping received : %d\n",number);

		number *= 2;

		fprintf(out,"%d\n",number);
		fflush(out);
			
	}

	close(pingPipe[1]);
	close(pongPipe[0]);
		
	waitpid(child,NULL);

	return EXIT_SUCCESS;
}

int child_process(int pongPipe[2], int pingPipe[2]){
	FILE* in,* out;
	char buffer[50];
	int number,i;

	close(pingPipe[1]);
	close(pongPipe[0]);

	in = fdopen(pingPipe[0],"r");
	out = fdopen(pongPipe[1],"w");

	fflush(in);
	for(i=0;i<NB_ITER;i++){
		printf("pong waiting...\n");
			
		while(fgets(buffer,sizeof(buffer), in) == NULL);

		number = atoi(buffer);

		printf("pong received: %d\n",number);

		number *= 2;

		fprintf(out,"%d\n",number);
		fflush(out);
		
	}

	close(pongPipe[1]);
	close(pingPipe[0]);

	return EXIT_SUCCESS;
}
