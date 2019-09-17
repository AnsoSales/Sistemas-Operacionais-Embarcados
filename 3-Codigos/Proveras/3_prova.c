#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char **argv)
	{
		int fp;
		char c = ' ';
		int i;

		fp = open(argv[1], O_WRONLY | O_CREAT, S_IRWXU);
		printf("%s\n\n",argv[0]);
		for (i = 2; i<argc; i++)
		{
			write(fp, argv[i],strlen(argv[i]));
			write(fp,&c,sizeof(c));
		}
		close(fp);
		return 0;
	}