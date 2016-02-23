#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	if(argc > 1)
	{
		int i;
		char* name = argv[0];;
		sleep(2);
		for(i=1;i<argc;++i)
		{
			printf("I'm %s <%d> and received = \" %s \" !\n",name,i-1,argv[i]);
			sleep(3);	
		}
		return i-2;
	}
	else
	{
		
		if(argc == 1)
		{
			printf("\n\n%s has not received arguments !!!\n\n",argv[0]);
		}
		else
		{
			printf("\n\nI have not received arguments !!!\n\n");
		}
	}
	return 0;
}
