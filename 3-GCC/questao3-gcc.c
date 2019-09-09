#include<stdio.h>
#include<stdlib.h>
#include <string.h>

	int main(int argc, const char **argv)
	{
		FILE *fp;
		char nova[20]="";
		strcat(nova,argv[1]);
		strcat(nova,".txt");
		fp = fopen(nova, "w");

		if (!fp)
		{
			printf("Erro na leitura do arquivo.");
			exit(0);
		}

		fprintf(fp,"Nome: %s\n",argv[1]);
		fprintf(fp,"Idade: %s\n",argv[2]);
		fclose(fp);
		return 0;
	}