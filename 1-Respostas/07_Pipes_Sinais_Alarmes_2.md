1. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Faça com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o número 10, ele aguarda 1 segundo e termina a execução. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.

```C
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
```

2. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

```C
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
```
3. Crie um programa em C que cria dois processos-filhos e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO1: Quando o vento passa, é a bandeira que se move.
FILHO2: Não, é o vento que se move.
PAI: Os dois se enganam. É a mente dos senhores que se move.
```
```C
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

```
Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.
```C
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


```
5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void alarmeson(int sig)
{
	system("ps");
}

void quitson(int sig)
{
	printf("Processo terminado!\n");
	exit(1);
}


int main()
{	
		signal(SIGALRM,alarmeson);
		signal(SIGINT,int_quitson);
		sleep(1);
		alarm(1);

return 0;
}
```