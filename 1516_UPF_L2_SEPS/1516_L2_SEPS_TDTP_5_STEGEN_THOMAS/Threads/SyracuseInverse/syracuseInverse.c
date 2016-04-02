/*
 * Code write by STEGEN Thomas - 16-03-2016
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/arboSyrac.h"

void* Thread(void* parameter) {
	// Initialisation de cur et base à la racine
	struct S_Cellule *cur = parameter,*racine = parameter;
	int i, valeur = cur->valeur, niveau = cur->niveau;
	
	for (i = 0; i < racine->niveau; ++i){
		// Modification de la valeur decrementation du niveau.
		valeur *= 2; niveau --;
		// Alloction de la nouvelle cellule et ajout dans le chainage.
		cur->pair = (S_Cellule *)malloc(sizeof(S_Cellule));
		cur = cur->pair;
		// Initialisation de la cellule.
		s_init_cellule(cur,valeur,niveau);
		//Affichage de la valeur actuelle.
		printf("Valeur suivante (%d)\n",valeur);
		// Condition: valeur - 1 multiple de 3 sauf valeur à 4.
		if(valeur != 4 && 0 == (valeur-1)%3){
			pthread_t ThreadId;
			// Ajout de racine de la nouvelle branche au chainage.
			cur->impair = (S_Cellule *)malloc(sizeof(S_Cellule));
			s_init_cellule(cur->impair,(valeur-1)/3,niveau);
			// Affichage de la création de la nouvelle branche.
			printf("Greffe d'une nouvelle branche (%d) de %d niveau(x)\n",(valeur-1)/3,niveau);
			// Création du thread de calcul qui génère la branche.
			pthread_create (&ThreadId, NULL, &Thread,  (void *)cur->impair);
			// variable créée temporairement pour récupérer le retour du thread
			S_Cellule *temp;
			// Mise en attente du créateur jusqu'à la fin du thread créé.
			pthread_join (ThreadId, (void **) &temp);
			// Affichage de la fin du thread créé..
			printf("Le thread de la branche (%d) est fini.\n",temp->valeur);
		}	
	}
	// Affichage signalant la fin de la branche
	printf("Branche explor%ce\n",130);
	// Retourne la branche terminée
	return (void *)racine;
}

int main (int argc,char * argv[] ) {
	// Initilisation de la base de l'arborescence.
	Syracuse syrac = syrac_init();
	// Initialisation de la valeur de base et du niveau.
	int valeur = 1, niveau = 7;
	// Demande du niveau à l'utilisateur
	printf("Quel niveau d'exploration de la branche d%csirez-vous?\n",130);
	do{
		scanf("%d",&niveau);
	}while(niveau < 0);
	// Initialisation de la cellule racine.
	syrac.racine = (S_Cellule *)malloc(sizeof(S_Cellule));
	s_init_cellule(syrac.racine,valeur,niveau);
	// Initialisation de l'id du thread
	pthread_t ThreadId;
	// Création du thread de calcul de base.
    pthread_create (&ThreadId, NULL, &Thread,  (void *)syrac.racine);
    // variable de récupération vi le join
	S_Cellule *temp;
	// Mise en attente du créateur jusqu'à la fin du thread créé.
	pthread_join (ThreadId, (void **) &temp);
	// Affichage de la fin du thread créé..
	printf("Le thread de la branche (%d) est fini.\n",temp->valeur);
	// Suppression de l'arborescence
	printf("%d éléments supprim%cs.\n",s_supprimer(syrac),130);
	return 0;
}
