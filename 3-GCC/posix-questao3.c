#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

	int main (int argc, const char **argv)
	{
		int fd;
		char *nome=(char*)malloc(100*sizeof(char));
		strcat(nome,argv[1]);
		strcat(nome,".txt");
		fd = open(nome,O_RDWR | O_CREAT);
		write(fd,"Nome: ",strlen("Nome: "));
		write(fd,argv[1],strlen(argv[1]));
		write(fd,"\n",strlen("\n"));
		write(fd,"Idade: ",strlen("Idade: "));
		write(fd,argv[2],strlen(argv[2]));
		write(fd,"\n",sizeof("\n"));
		close(fd);
		return 0;
	}