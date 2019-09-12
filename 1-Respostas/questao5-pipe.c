#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define N 30

int main()
{
	char buffer_pai[N];
	char buffer_filho[N];
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i;

	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{
		read(fd[0], buffer_filho, N);
		printf("%s",buffer_filho);
	}
	// Codigo do pai
	else
	{
		for (i = 1; i<=10; i++)
		{
		sleep(1);
		write(fd[1], i, N);
		}
		return -1;
	}
	return 0;
}