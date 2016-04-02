/*
 * Code write by STEGEN Thomas - 31-03-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char * argv[]) {
	char buffer[50], cmd[] = "ls ";
	FILE* stream;
	int i = 0;
	// ajoute le chemin à la commande
	strcat(cmd,argv[argc-1]);
	// lance le programme et demande un pointeur vers son entrée standart
	stream = popen(cmd,"r");
	// lit tant qu'il y a des éléments
	while(!feof(stream) && !ferror(stream) && fgets(buffer,sizeof(buffer),stream))
		// affiche les éléments
		printf("élément %d : %s",++i ,buffer);
	// affiche le nombre d'élément
	printf("Total:  %d fichier(s)\n",i);
	return pclose(stream);
}
