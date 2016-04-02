#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int i,it=10;
	pid_t child,second;
	child = fork();
	if(child == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if(child == 0)
	{
		printf("<%d> i'm second? my father is %d\n",getpid(),getppid());
		child = fork();
		if(child == -1)
		{
			perror("second Fork error");
			exit(EXIT_FAILURE);
		}
		if(child == 0)
		{
			printf("<%d> i'm third? my father is %d\n",getpid(),getppid());
			_exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		printf("<%d> i'm first? my first child is %d\n",getpid(),child);
		sleep(5);
		second = fork();
		if(second == -1)
		{
			perror("second Fork error");
			exit(EXIT_FAILURE);
		}
		if(second == 0)
		{
			printf("<%d> i'm fourth? my father is %d\n",getpid(),getppid());
			_exit(EXIT_SUCCESS);
		}
		else
		{
			printf("<%d> my second child is %d\n",getpid(),getppid());
			sleep(10);
			printf("<%d> Quelle bonne sieste!!!\n",getpid());
			exit(EXIT_SUCCESS);
		}
	}
}
