/*
 * Code write by STEGEN Thomas - 14-03-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h> 

void* print (void* unused) {
	// Initialisation des paroles.
	char parole[][50] = {"Vent frais, vent du matin"
                        ,"Vent qui souffle au sommet des grands pins"
                        ,"Joie du vent qui passe"
                        ,"Allons dans le grand ..."};
	// Boucle d'affichage des paroles choisie aléatoirement.
    while (1){
        printf("%s\n", parole[rand()%3]);
		sleep(5);
    }
    return NULL;
}

int main () {
	int i;
	// initialisation des threads Id
    pthread_t ThreadId[6];
	// boucle de création des threads
    for (i = 0; i < 6; ++i)
        pthread_create (&ThreadId[i], NULL, &print,  NULL);
	// boucle infinie d'affichage
    while (1){
		sleep(1);
        printf("Vous allez arreter oui!\n");
    }
    return 0;
} 
