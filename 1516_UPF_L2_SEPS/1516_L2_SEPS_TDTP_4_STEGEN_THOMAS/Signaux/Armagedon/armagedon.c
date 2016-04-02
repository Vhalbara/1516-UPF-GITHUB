#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>	// u_sleep
#include <signal.h>		// librairie des signaux

#define   MAX_COUNT  20 // Nombre de tour de boucle
#define   MAX_FORK  4	// Nombr de fils à créer

pid_t pids[MAX_FORK]; // Par faciliter, j'utilise la variable globale

void  ChildProcess(void);	// Prototype des processus fils
void  ParentProcess(void);	// Prototype du processus père

void sonSigHandler (int);	// Prototype du handler

int  main(void)
{
     int i,n = MAX_FORK;

     /* Lance les fils */
	for (i = 0; i < n; ++i) {
		if ((pids[i] = fork()) < 0) {	// création ratée
			perror("fork");
			_exit(EXIT_FAILURE);
		}
		if (pids[i] == 0) {		// création réussie
			ChildProcess();	// "Lance" le processus fils
			_exit(EXIT_SUCCESS);
		}
	}

    ParentProcess(); // "Lance" le processus père

	/* Attend la fin de ses fils */
    int status;
    pid_t pid;
	while (n > 0) {
		pid = wait(&status);
		printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
		--n;
	}

	_exit(EXIT_SUCCESS);
}

void  ChildProcess(void)
{
    int   i;
    struct sigaction SigAction;

    SigAction.sa_handler = sonSigHandler;
    sigemptyset(&SigAction.sa_mask);
    SigAction.sa_flags = 0;

    if(sigaction(SIGUSR1,&SigAction,NULL)  == -1)
         perror("Erreur d'armement du signal SIGUSR1");

	if(sigaction(SIGINT,&SigAction,NULL)  == -1)
         perror("Erreur d'armement du signal SIGINT");

    for (i = 1; i <= MAX_COUNT; i++)
         printf("<child %d>This line is from child, value = %d\n", getpid(), i);

    printf("*** Child %d process is done ***\n", getpid());
}

void  ParentProcess(void)
{
	usleep(1); // Mettre une pause force le scheduller à donner la main aux autres process

	printf("\n\nmy children are %d, %d, %d, %d\n\n", pids[0], pids[1], pids[2], pids[3]);
    
	int   i;

    for (i = 1; i <= MAX_COUNT; i++) // Le père affiche des message en boucle
		printf("<father %d>This line is from parent, value = %d\n", getpid(), i);

    for (i = 0; i < MAX_FORK; i++){ // Le père envoie les signaux
		printf("<father %d> I transmit a SIGUSR1 to %d\n", getpid(), pids[i]);
        kill(pids[i],SIGUSR1);
    }

    printf("*** Parent is done ***\n"); // Le père prévient qu'il a terminer
}

void sonSigHandler (int signum){
	switch(signum){
	case SIGUSR1:
		printf("<child %d> i received a SIGUSR1\n", getpid());
        kill(getpid(),SIGINT);
        break;
	case SIGINT:
		printf("*** Child %d process is done by SIGINT ***\n", getpid());
		_exit(EXIT_SUCCESS);
        break;
	default:
        printf("<fils %d> Reception d'un signal inconnu\n", getpid());
	}
}
