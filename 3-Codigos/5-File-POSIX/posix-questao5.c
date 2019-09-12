#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

char *le_arq_texto(char *nome_arquivo)
{
		
	int fl;
	char *tam=(char*)malloc(100*sizeof(char));
	char *conteudo=(char*)malloc(100*sizeof(char));
	long tamanho;	
	fl=open(nome_arquivo,O_RDWR | O_CREAT, S_IRWXU);

		
		read(fl,tam,sizeof(char)*100);
		close(fl);
		
	
return tam;
free(tam);
}

int main()
{
	char* arquivo=(char *)malloc(100*sizeof(char));
	long tamanho;
	printf("digite o nome do arquivo: ");
	scanf("%s", arquivo);
	
	printf("%s",le_arq_texto(arquivo));
	free(arquivo);
return 0;
}