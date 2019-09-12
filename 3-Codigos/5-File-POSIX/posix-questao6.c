#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, const char **argv)
{
	int fl;
	char* arquivo=(char *)malloc(100*sizeof(char));
		fl=open(argv[1],O_RDWR | O_CREAT, S_IRWXU);		
		read(fl,arquivo,sizeof(char)*100);
		close(fl);
	printf("%s",arquivo);
	free(arquivo);
return 0;
}