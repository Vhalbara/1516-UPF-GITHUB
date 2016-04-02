#ifndef _ERATOS_H_
#define _ERATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX 4 294 967 295 // valeur maximale unsigned long

typedef struct
{
    unsigned long valeur; // prend en compte de très long nombre
    void* svt;
	void* rec;
}Cellule;

typedef struct
{
    Cellule* premier;
    Cellule* dernier;
}Eratos;

void e_init_cellule(Cellule *,unsigned long val, Cellule *svt, Cellule *rec);
Eratos e_initialiser (int n);
int e_supprimer (Eratos* eratos);
void e_afficher(Eratos* eratos);
void e_cribler(Eratos *eratos,int n);
void e_ranger(Eratos *eratos);
unsigned long e_sommer (Eratos *eratos);
unsigned long e_sommer_partie (Eratos *eratos,int start, int end);

#endif
