#include<stdio.h>
#include<stdlib.h>
#include <string.h>

	void main()
	{
		char nome[20];
		int idade;
		printf("Digite o seu nome:\n");
		//gets(nome);
		scanf("%s", nome);
		printf("Digite sua idade:\n");
		scanf("%d", &idade);
		FILE *fp;
		char nova[20]="";
		strcat(nova,nome);
		strcat(nova,".txt");
		fp = fopen(nova, "w");

		if (!fp)
		{
			printf("Erro na leitura do arquivo.");
			exit(0);
		}

		fprintf(fp,"Nome: %s\n",nome);
		fprintf(fp,"Idade: %d\n",idade);
		fclose(fp);
	}