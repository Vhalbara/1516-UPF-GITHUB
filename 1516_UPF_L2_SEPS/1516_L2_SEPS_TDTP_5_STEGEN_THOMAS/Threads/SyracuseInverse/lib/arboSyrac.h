#ifndef _ARBO_SYRAC_H_
#define _ARBO_SYRAC_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct S_Cellule{
	int valeur;
	int niveau;
	void* pair;
	void* impair;
}S_Cellule;

typedef struct {
	struct S_Cellule *racine;
	int niveau;
}Syracuse;

Syracuse syrac_init ();
void s_init_cellule(S_Cellule *cellule, int valeur, int niveau);
int s_supprimer (Syracuse syrac);
int s_supprimer_branche (S_Cellule *base);

#endif
