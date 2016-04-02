#include "eratos.h"

void e_init_cellule(Cellule* cur, unsigned long val, Cellule *svt, Cellule *rec){
	cur->valeur = val;
    cur->svt = svt;
	cur->rec = rec;
}

Eratos e_initialiser (int n){
	Eratos eratos;
	Cellule *data,*prec;	
	int i;
	
	data = (Cellule *)malloc(sizeof(Cellule));
	if(data == NULL)
		return ;

	e_init_cellule(data,FALSE,NULL,NULL);
		
	eratos.premier = data;
	prec = data;

	data = (Cellule *)malloc(sizeof(Cellule));
	if(data == NULL)
		return ;

	e_init_cellule(data,FALSE,NULL,prec);
	prec->svt = data;

	for(i=2;i<n;++i){
		prec = data;
		data = (Cellule *)malloc(sizeof(Cellule));
		if(data == NULL)
			return ;

		e_init_cellule(data,TRUE,NULL,prec);
		prec->svt = data;
	}
	
	eratos.dernier = data;
	return eratos;
}

int e_supprimer (Eratos* eratos)
{
	int i=0;
    Cellule *data,*temp;

	data = eratos->dernier;

	while(data != NULL){
		temp = data;
		data = data->rec;
		free(temp);
		i++;
	}
	
	eratos->premier = eratos->dernier = NULL;
    return i;
}

void e_afficher(Eratos* eratos){

	int it=0;
    Cellule *data,*temp;
	
    if(eratos->premier == NULL)
		return ;

	printf("\n|  0 ||  1 ||  2 ||  3 ||  4 ||  5 ||  6 ||  7 ||  8 ||  9 |\n\n");
	data = eratos->premier;

	while(data != NULL){
		printf("| %2ld |", data->valeur);
		if((it+1)%10 == FALSE)  printf("\n");
		data = data->svt;		
		it++;
	}
}

Cellule* e_goto(Eratos* eratos, int pos){
	
	if(pos == 0) return eratos->premier;

	int it;
	Cellule* temp = eratos->premier;

	for(it=0;it<pos;++it){	
		temp = temp->svt;
	}
	
	return temp;
}

void e_cribler(Eratos *eratos,int n){

    int k=2,j, racine=(int)sqrt((double)n)+1;

    while (k<=racine){

        for (j=k;j*k<n;j++)
            e_goto(eratos,j*k)->valeur=FALSE;
        k++;

        while (! e_goto(eratos,k)->valeur)
            k++;
    }
}

void e_ranger(Eratos *eratos){

	int it=0;
	Cellule *data = eratos->premier;

	while(data != NULL){
		data->valeur *= it++;
		data = data->svt;	
	}
}

unsigned long e_sommer (Eratos *eratos){
	unsigned long somme=0;
	Cellule *data = eratos->premier;

	while(data != NULL){
		somme += data->valeur;
		data = data->svt;	
	}

	return somme;
}

unsigned long e_sommer_partie (Eratos *eratos,int start, int end){
	int somme=0;
	Cellule *data = e_goto(eratos,start);

	while(data != NULL && start<=end){
		somme += data->valeur;
		data = data->svt;
		start ++;
	}
	
	return somme;
}
