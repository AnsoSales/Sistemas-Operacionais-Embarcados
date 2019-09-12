#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 30
int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i,a;
	char buffer_pai[N];
	char buffer_filho[N];
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{
		while(1)
		{
		sleep(1);
		//buffer_filho=atoi(fd[0]);
		read(fd[0], buffer_filho, N);
		a = atoi(buffer_filho);
		printf("%d\n",a);
		wait(NULL);
		}

	}
	// Codigo do pai
	else
	{
		for (i = 1; i<=10; i++)
		{

		
		sprintf(buffer_pai,"%d",i);
		write(fd[1],buffer_pai, N);
		sleep(1);
		}
		{return -1;}	
	}
	return 0;
}