/*
 * Written by Thomas Stegen for the development in numerical analysis at the UPF
 */

#include <stdio.h>
#include <math.h>
#include "lib/numerical_analysis.h"

int main(int argc, char *argv[]) {
	
	double a = sqrt(2.0),b = 2.0;
	printf("Il y a ");
	if(COMPARISON_REAL(a*a,b,0.0000000000000008))
		printf("%cgalit%c!!\n",130,130);
	else
		printf("pas d'%cgalit%c\n",130,130);
	
	return 0;
}
