#include<stdio.h>
#include<stdlib.h>
#include <string.h>

	long int tam_arq_texto(char *nome_arquivo)
	{
		FILE *fp;
		long int tamanho=0;
		fp = fopen(nome_arquivo,"rb");
		if (!fp)
		{
			printf("Erro na leitura do arquivo.");
			exit(0);
		}
		fseek(fp,0,SEEK_END);
		tamanho = ftell(fp);
		return tamanho;
	}

int main(){
	char *nome;
	scanf("%s", nome);	
	long int saize = tam_arq_texto(nome);
	printf("%ld\n",saize);


	return 0;


}