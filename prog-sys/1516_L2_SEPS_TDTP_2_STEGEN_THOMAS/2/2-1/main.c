#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	if(argc > 1)
	{
		int i;
		char* name = argv[1];;
		for(i=2;i<argc;++i)
		{
			printf("I'm %s <%d> and received = \" %s \" !\n",name,i-2,argv[i]);
			sleep(3);	
		}
	}
	else
		printf("\n\nI have not received arguments !!!\n\n");
	return i-2;
}
