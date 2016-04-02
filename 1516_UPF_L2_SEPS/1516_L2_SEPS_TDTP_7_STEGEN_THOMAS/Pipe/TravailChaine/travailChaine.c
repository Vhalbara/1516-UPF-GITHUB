/*
 * Code write by STEGEN Thomas - 14-03-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

//#define ALTERNACE_THREAD
#define NB_VAL 6

struct Parameter{
	int nb;
	int *pipe;
};

int RANDOM(a,b) {
	return rand()%(b-a)+a;
}

void* provider (void* used) {
	struct Parameter *parameter = used;
	// place le pointeur sur le flux.
	FILE* stream = fdopen(*((parameter->pipe)+1),"w");
	// essaie d'allouer de la mémoire pour calculé la somme.
	int * somme = (int*) malloc(sizeof(int));
	int i, val;
	// vérifie que l'espace a pu être alloué.
	if(somme == NULL) return NULL;
	// initialise la somme à 0.
	*somme = 0;
	for(i=0;i<parameter->nb;++i){
		// tire un nombre aléatoire
		val = RANDOM(1,100);
		printf("<Provider> Nombre choisis : %d.\n",val);
		// envoie dans le pipe..
		fprintf(stream,"%d\n",val);
		printf("<Provider> Message mis en forme.\n");
		// confirme de l'écriture.
		fflush(stream);
		printf("<Provider> Envoi confirmé.\n");
		// ajoute à la somme.
		*somme += val;
		printf("<Provider> Somme calculée : %d.\n",*somme);
#ifdef ALTERNACE_THREAD
		// pause pour simuler l'alternance.
		usleep(10);
#endif
	}
	// retourne la somme calculée.
    return (void *)somme;
}

void* sumpup (void* used) {
	struct Parameter *parameter = used;
	// place le pointeur sur le flux.
	FILE* stream = fdopen(*((parameter->pipe)+1),"w");
	// essaie d'allouer de la mémoire pour calculé la somme.
	int * somme = (int*) malloc(sizeof(int));
	// réserve la place pour récupérer le message.
	char buffer[11];
	int i, val;
	// vérifie que l'espace a pu être alloué.
	if(somme == NULL) return NULL;
	// initialise la somme à 0.
	*somme = 0;

	for(i=0;i<parameter->nb;++i){
		// attend puis récupère le message.
		while(fgets(buffer,sizeof(buffer),stream) == NULL);
		printf("<SumUp> Message reçu : %s",buffer);
		// converti le message.
		val = atoi(buffer);
		printf("<SumUp> Message converti : %d.\n",val);
		// ajoute à la somme.
		*somme += val;
		printf("<SumUp> Somme calculée : %d.\n",*somme);
#ifdef ALTERNACE_THREAD
		// pause pour simuler l'alternance.
		usleep(10);
#endif
	}
	// retourne la somme calculée.
    return (void *)somme;
}

int main () {
	// "ouvre le tube".
	int pipeInt[2];
	pipe(pipeInt);
	// initialise les paramètres.
	struct Parameter parameter[] = {{NB_VAL,pipeInt},{NB_VAL,pipeInt}};
	// initialise "les variables threadId"
    pthread_t Provider;
	pthread_t Sumpup;
	// crée les threads.
    pthread_create (&Provider, NULL, &provider,  (void *)&parameter[0]);
    pthread_create (&Sumpup, NULL, &sumpup,  (void *)&parameter[1]);
	// initialise la variable d récupération.
	int * temp = NULL;
	// attend la fin de Provider pour récupérer la somme calculée.
	pthread_join (Provider, (void **) &temp);
	// est-ce que la somme a pu être calculée
	if(temp != NULL){
		printf("La somme calculée par Provider est de %d.\n",*temp);
		// libère la mémoire allouée.
		free(temp);
	}else // error
		printf("La somme n'a pas pu être calculée par Provider.\n");
	// attend la fin de SumUp pour récupérer la somme calculée.	
	pthread_join (Sumpup, (void **) &temp);
	// est-ce que la somme a pu être calculée
	if(temp != NULL){
		printf("La somme calculée par SumUp est de %d.\n",*temp);
		// libère la mémoire allouée.
		free(temp);
	}else //error
		printf("La somme n'a pas pu être calculée par SumUp.\n");

    return 0;
} 
