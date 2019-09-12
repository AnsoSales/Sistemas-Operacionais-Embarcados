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
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i,a;
	
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0)
	{
	
	char buffer_filho[N],mensagem_filho[N];
	sprintf(mensagem_filho,"Pai, qual é a verdadeira essência da sabedoria?");
	write(fd[1],mensagem_filho,N);
	sleep(1);
	read(fd[0],buffer_filho,N);
	printf("PAI: %s\n",buffer_filho);
	sprintf(mensagem_filho,"Mas até uma criança de três anos sabe disso!");
	write(fd[1],mensagem_filho,N);
	sleep(2);
	read(fd[0],buffer_filho,N);
	printf("PAI: %s\n",buffer_filho);

	}
	// Codigo do pai
	else
	{
	char buffer_pai[N],mensagem_pai[N];
	read(fd[0],buffer_pai,N);
	printf("FILHO: %s\n",buffer_pai);
	sprintf(mensagem_pai,"Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
	write(fd[1],mensagem_pai,N);
	sleep(2);
	read(fd[0],buffer_pai,N);
	printf("FILHO: %s\n",buffer_pai);
	sprintf(mensagem_pai,"Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
	write(fd[1],mensagem_pai,N);
	wait(NULL);
	}
	return 0;
}

/*FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...*/
