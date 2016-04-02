#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int i,it=10;
	if(argc>1)
	it = atoi(argv[1]);
	
	pid_t child;
	child = fork();
	if(child == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if(child == 0)
	{
		for(i=0;i<it;++i)
		{
			printf("<%d> my father is %d\n",getpid(),getppid());
			sleep(2);
		}
		_exit(EXIT_SUCCESS);
	}
	else
	{
		for(i=0;i<it;++i)
		{
			printf("<%d> my child is %d\n",getpid(),child);
			sleep(1);
		}
		wait(NULL);
		printf("<%d> Quelle bonne sieste!!!\n",getpid());
		exit(EXIT_SUCCESS);
	}
}
