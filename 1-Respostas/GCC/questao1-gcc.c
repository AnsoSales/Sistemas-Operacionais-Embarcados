#include<stdio.h>
#include<stdlib.h>

	void main()
	{
		FILE *fp;
		fp = fopen("arquivo.txt", "w");

		if (!fp)
		{
			printf("Erro na leitura do arquivo.");
			exit(0);
		}

		fprintf(fp, "ola mundo");
		fclose(fp);
		return 0;
	}