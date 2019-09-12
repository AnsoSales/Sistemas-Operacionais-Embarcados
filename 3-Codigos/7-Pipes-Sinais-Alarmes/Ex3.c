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
		sprintf(msg_f1,"FILHO1: Quando o vento passa, é a bandeira que se move.");
		write(fd[1],msg_f1,N);
		sleep(1);
		
	}
	else
	{
		// Codigo do filho 2
		pid2=fork();
		if (pid2==0)
		{

		char msg_f2[N];
		read(fd[0],msg_f2,N);
		printf("%s\n",msg_f2);
		sprintf(msg_f2,"FILHO2: Não, é o vento que se move.");
		write(fd[1],msg_f2,N);
		
		
		}
		else
		{
		sleep(1);
		char msg_p[N];
		read(fd[0],msg_p,N);
		printf("%s\n",msg_p);
		sprintf(msg_p,"PAI: Os dois se enganam. É a mente dos senhores que se move.");
		write(fd[1],msg_p,N);
		printf("%s",msg_p);
		sleep(1);
		{return -1;}
	}

		
	}
	return 0;
}

/*FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...*/
