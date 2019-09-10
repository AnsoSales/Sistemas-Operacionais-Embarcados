#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

long tam_arq_texto(char *nome_arquivo)
{
		
	int fl;
	char *tam=(char*)malloc(100*sizeof(char));
	long tamanho;	
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);

		
		tamanho= read(fl,tam,sizeof(char)*100);
		close(fl);
		free(tam);
	
return tamanho;
}

int main()
{
	char* arquivo=(char *)malloc(100*sizeof(char));
	long tamanho;
	printf("digite o nome do arquivo: ");
	scanf("%s", arquivo);
	tamanho=tam_arq_texto(arquivo);
	printf("%ld bytes\n", tamanho);
	free(arquivo);
return 0;
}