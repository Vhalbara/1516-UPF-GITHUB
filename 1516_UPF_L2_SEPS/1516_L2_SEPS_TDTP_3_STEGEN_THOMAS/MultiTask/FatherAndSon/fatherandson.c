#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int i;
	pid_t child;
	child = fork();
	if(child == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if(child == 0)
	{
		printf("<%d> Mon pid est %d et celui de mon pere est %d\n",getpid(),getpid(),getppid());
		sleep(4);
		printf("<%d> Quelle bonne sieste!!!\n",getpid());
		_exit(EXIT_SUCCESS);
	}
	else
	{
		printf("<%d> Mon pid est %d et celui de mon fils est %d\n",getpid(),getpid(),child);
		sleep(5);
		printf("<%d> Quelle bonne sieste!!!\n",getpid());
		exit(EXIT_SUCCESS);
	}
}
