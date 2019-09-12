#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

	int main (int argc, const char **argv)
	{
		int fd;
		char *nome=(char*)malloc(100*sizeof(char));
		fd = open(argv[2],O_RDWR | O_CREAT);
		write(fd,argv[1],strlen(argv[1]));
		close(fd);
		return 0;
	}