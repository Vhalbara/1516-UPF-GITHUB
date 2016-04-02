#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void signalHandler (int);

int main (){
	int i;
	struct sigaction SigAction;

	printf("pid : %ld\n",getpid());
	
	SigAction.sa_handler = signalHandler;
	sigemptyset(&SigAction.sa_mask);
	SigAction.sa_flags = 0;
	
	if(sigaction(SIGINT,&SigAction,NULL)  == -1)
		perror("Erreur d'armement du signal SIGINT");

	for(i=0;i<15;i++){
		sleep(1);
 		printf("Veuillez appuyer sur ctrl-C\n");
	}
	exit(0);
}

void signalHandler (int signum){
	switch(signum){
	case SIGINT:
		printf("<signalHandler> Reception du signal SIGINT\n");
		printf("<signalHandler> Sortie de HandlerInt\n");
		break;
	default:
		printf("<signalHandler> Reception d'un signal inconnu\n");
	}
}
