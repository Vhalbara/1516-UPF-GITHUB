#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void HandlerInt (int);
void HandlerUsr (int);

int main (){
	struct sigaction SigAction;

	printf("pid : %ld\n",getpid());
	
	SigAction.sa_handler = HandlerInt;
	sigemptyset(&SigAction.sa_mask);
	SigAction.sa_flags = 0;
	
	if(sigaction(SIGINT,&SigAction,NULL)  == -1)
		perror("Erreur d'armement du signal SIGINT");

	SigAction.sa_handler = HandlerUsr;
	sigemptyset(&SigAction.sa_mask);
	SigAction.sa_flags = 0;
	
	if(sigaction(SIGUSR1,&SigAction,NULL)  == -1)
		perror("Erreur d'armement du signal SIGUSR1");

	while(1) kill(getpid(),SIGUSR1);

	exit(0);
}

void HandlerInt (int sig){
	printf("<SIGINT> Reception du signal\n");
	printf("<SIGINT> Sortie de HandlerInt\n");
	exit(0);
}

void HandlerUsr (int sig){
	printf("<SIGUSR1> Reception du signal\n");
	sleep(5);
	printf("<SIGUSR1> Sortie de HandlerUsr\n");
}
