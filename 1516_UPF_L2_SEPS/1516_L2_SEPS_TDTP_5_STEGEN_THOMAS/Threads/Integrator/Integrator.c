#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <time.h> 
#include "eratos/eratos.h"

struct params {
	Eratos *eratos;
	int start;
	int end;
};

void* integrator(void* parameters) {
	clock_t t;
	unsigned long *somme = (unsigned long*)malloc(sizeof(unsigned long));;
	struct params* p = (struct params*) parameters;
	// Affichage d'un message au cdébut du traitement.
	printf ("<fils> Traitement entre %ld et %ld\n", p->start, p->end);
	t = clock();
	// Calcul de la somme entre les deux bornes.
	(*somme) = e_sommer_partie (p->eratos, p->start, p->end);
	t = clock() - t;
	// Affichage à la fin du traitement et du temps de calcul.
	printf ("<fils> Traitement fait en %f, %ld\n", ((float)t)/CLOCKS_PER_SEC, (*somme));
	// Retour de la somme calculée
	return (void *)somme;
}

int main (int argc,char * argv[] ) {
	int i,nb = (argc>1)?atoi(argv[1]):5, n = (argc>2)?atoi(argv[2]):50000, prog = n/nb;
	// Initialisation la liste des nombres premier avant la borne.
	Eratos test = e_initialiser(n);
	e_cribler(&test,n);
	e_ranger(&test);
	// Initialisation du tableau d'Id des threads.
	pthread_t ThreadId[nb];
	struct params paramsThread[nb];
	// Initialisation des paramètres des différents threads.
	paramsThread[0].eratos = &test;
	paramsThread[0].start = 0;
	paramsThread[0].end = prog-1;
	for(i=1; i < nb ; ++i){
		paramsThread[i].eratos = &test;
		paramsThread[i].start = paramsThread[i-1].start + prog;
		paramsThread[i].end = paramsThread[i].start+prog-1;
	}
	// Création des threads.
    for (i = 0; i < nb; ++i){
        pthread_create (&ThreadId[i], NULL, &integrator,  (void*)&paramsThread[i]);
		usleep(400);
    }
	// Mise en pause jusqu'à la fin de ses threads et somme des valeurs retournées par le thread.
	unsigned long *buffer = NULL,somme = 0;
    for (i = 0; i < nb; ++i){
        pthread_join (ThreadId[i], (void **) &buffer);
        printf("<pere> Thread %d reçu avec %ld\n", i,*buffer);
		somme += *buffer;
		free(buffer);
    }
	// Affichage de la somme calculée par le processus principal puis par les threads.
	printf("<pere> La somme calcule par les thread est de %ld\n",somme);	
	clock_t t = clock();
	somme = (e_sommer(&test));
	t = clock() - t;
	printf("<pere> La somme est de %ld et faite en %f sec\n",somme,((float)t)/CLOCKS_PER_SEC);
	// Affichage du nombre d'éléments supprimés.
	printf("<pere> %d elements ont été supprimés\n",e_supprimer (&test));

	return 0;
}
