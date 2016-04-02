#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void fatherSigHandler (int);
void sonSigHandler (int);

int main (){
	int i;
	struct sigaction SigAction;

	pid_t child;
	child = fork();
	if(child == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if(child == 0)
	{
		sigignore(SIGINT);	// Désactive le signal
	
		for(i=0;i<10;i++){
			sleep(1);
			printf("<fils> ...\n");		
		}

		sigset(SIGINT); // Réactive le signal

		SigAction.sa_handler = sonSigHandler;
		sigemptyset(&SigAction.sa_mask);
		SigAction.sa_flags = 0;
	
		if(sigaction(SIGINT,&SigAction,NULL)  == -1)
			perror("Erreur d'armement du signal SIGINT");

		if(sigaction(SIGALRM,&SigAction,NULL)  == -1)
			perror("Erreur d'armement du signal SIGALRM");
		
		alarm(20);

		while(1){
			sleep(1);
			printf("<fils> ...\n");	
		}

	}
	else
	{
		printf("pid : %ld\n",getpid());
	
		SigAction.sa_handler = fatherSigHandler;
		sigemptyset(&SigAction.sa_mask);
		SigAction.sa_flags = 0;
	
		if(sigaction(SIGCHLD,&SigAction,NULL)  == -1)
			perror("Erreur d'armement du signal SIGCHLD");

		while(1){
			sleep(3);
	 		printf("<père>Envoi de la commande ctrl-C\n");
			kill(child,SIGINT);
		}
	}
	exit(0);
}

void fatherSigHandler (int signum){
	switch(signum){
	case SIGCHLD:
		printf("<père> Reviens ici!!!!!\n");
		exit(0);
		break;
	default:
		printf("<signalHandler> Reception d'un signal inconnu\n");
	}

}
void sonSigHandler (int signum){
	switch(signum){
	case SIGINT:
		printf("<fils> touch%c\n",132);
		break;
	case SIGALRM:
		printf("<fils> J'en ai marre, je me casse\n");
		exit(0);
		break;
	default:
		printf("<signalHandler> Reception d'un signal inconnu\n");
	}

}
