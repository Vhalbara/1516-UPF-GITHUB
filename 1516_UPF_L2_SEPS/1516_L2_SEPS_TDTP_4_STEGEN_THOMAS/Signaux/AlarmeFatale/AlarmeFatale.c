#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void AlarmeHandler (int);

int main (){
	int i;
	char tab[][50]={"belle,belle,belle","comme le jour","elle sont toutes","belle,belle,belle","comme le jour"};
	struct sigaction SigAction;

	SigAction.sa_handler = AlarmeHandler;
	sigemptyset(&SigAction.sa_mask);
	SigAction.sa_flags = 0;

	if(sigaction(SIGALRM,&SigAction,NULL)  == -1)
		perror("Erreur d'armement du signal SIGALRM");

	alarm(2);
	for(i=0;i<5;i++){
		sleep(1);
		printf("%s\n",tab[i]);
	}
	exit(0);
}

void AlarmeHandler (int signum){
	switch(signum){
	case SIGALRM:
		printf("<Alarme> DRING, DRING, DRING\n");
		alarm(2);
		break;
	default:
		printf("<Alarme> Reception d'un signal inconnu\n");
	}

}
