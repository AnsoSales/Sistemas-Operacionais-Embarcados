


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
printf("%d\n",getpipe());
return 0;
}