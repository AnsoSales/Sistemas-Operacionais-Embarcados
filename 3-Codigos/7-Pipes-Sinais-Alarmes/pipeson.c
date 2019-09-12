
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int pid;
int fd[2];
pid = fork();
pipe(fd);
if (pid == 0)
{
	printf("processo filho PID %d\n",getpid());

}
else
{
	sleep(1);
	printf("Processo do pai PID %d\n",getpid());
}

return(0);
}