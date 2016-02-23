#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define FATHER

int main(int argc, char *argv[]) {
	int result=0;
	if(argc > 1)
	{
		int i;
		int a = atoi(argv[1]),b = atoi(argv[3]);
		if(*(argv[2]) == '+')
			result = a+b;
		if(*(argv[2]) == '-')
			result = a-b;
		if(*(argv[2]) == '*')
			result = a*b;
		if(*(argv[2]) == '/')
			result = a/b;
#ifndef FATHER
		printf("La valeur est %d!\n",result);
#endif
	}
	ExitProcess(result);
}

