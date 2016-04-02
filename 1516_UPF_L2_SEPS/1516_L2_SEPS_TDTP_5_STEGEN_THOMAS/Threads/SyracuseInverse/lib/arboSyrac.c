#include "arboSyrac.h"

Syracuse syrac_init (){
	// Création de l'instance de syracuse.
	Syracuse syrac;
	// Initialisation de l'instance.
	syrac.racine = NULL;
	syrac.niveau = 0;
	// Retourne l'instance.
	return syrac;
}

void s_init_cellule(S_Cellule *cellule, int valeur, int niveau){
	// Initialisation de la cellule.
	cellule->valeur = valeur;
	cellule->niveau = niveau;
	cellule->pair = NULL;
	cellule->impair = NULL;
}

int s_supprimer (Syracuse syrac){
	// Binding de la suppresion s_supprimer_branche.
	return s_supprimer_branche(syrac.racine);
}

int s_supprimer_branche (S_Cellule *base){
	// Initialisation du compteur
	int i = 0;
	// Initialise la base de la branche.
	S_Cellule *cellule = base;
	// Boucle jusqu'à la fin de la branche.
	while(cellule != NULL){
		// Si il y a une branche, on la supprime.
		if(cellule->impair != NULL)
			i += s_supprimer_branche(cellule->impair);
		// Base garde temporairement la cellule pair.
		base = cellule->pair;
		// Supprime la cellule courrante.
		free(cellule);
		// Cellule récupère la cellule suivante.
		cellule = base;
		// incrémente le compteur.
		i++;
	}
	// Retourne le nombre de suppression
	return i;
}

