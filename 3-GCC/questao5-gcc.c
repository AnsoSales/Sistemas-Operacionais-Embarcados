#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *le_arq_texto(char* nome_arquivo)
{
		FILE *fp;
		char *name;
		name= (char *) malloc(100*sizeof(char));
		fp = fopen(nome_arquivo,"rb");
		if (!fp)
		{
			printf("Erro na leitura do arquivo.");
			exit(0);
		}
		fread(&name[0],sizeof(double),sizeof(char),fp);
		return name;
		free(name);
	}

int main()
{
	char arquivo[100];
	scanf("%s", arquivo);
	printf("%s\n", le_arq_texto(arquivo));	
	return 0;
}