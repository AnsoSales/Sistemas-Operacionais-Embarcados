#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 100
int main()
{
	int pid,pid2;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i,a;
	
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho 1
	if(pid == 0)
	{
		char msg_f1[N];
		printf("Digite o seu nome: \n");
		scanf("%[^\n]s",msg_f1);
		sleep(1);
		write(fd[1],msg_f1,N);
		
	}
		else
		{
		
		char msg_p[N];
		read(fd[0],msg_p,N);
		printf("%s\n",msg_p);
		sleep(1);
		{return -1;}
	}

		
	
	return 0;
}

