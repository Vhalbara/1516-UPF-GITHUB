#include <stdio.h>
#include <stdlib.h>

#include "../config"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;

	printf("Disrupteur Dimensionnel activ%c !\n",130);
	
	printf("\nL'univers est en expansion!\n\n");
	
	printf("-> count down : 10\n");
	for(i=MAX-1;i >= 0;--i)
	{
		sleep(TIME_CHILD);
		printf("-> count down : %d\n",i);
	}
	sleep(1);
	printf("\n\nBang !\n\n");
	
	return 0;
}
