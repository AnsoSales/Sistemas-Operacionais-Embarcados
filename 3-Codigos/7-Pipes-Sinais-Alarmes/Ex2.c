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