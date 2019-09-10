#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

	int main (int argc, const char **argv)
	{
		int fd,idade=0;
		//char *nome=(char*)malloc(100*sizeof(char));
		char nome[100];
		char names[100];
		char ids[12]="";
		printf("digite o seu nome: ");
		scanf("%s", nome);
		strcat(names,nome);
		strcat(names,".txt");
		printf("digite a sua idade: ");
		scanf("%d",&idade);
		sprintf(ids,"%d",idade);
		fd = open(names,O_WRONLY | O_CREAT);
				write(fd,"Nome: ",strlen("Nome: "));
				write(fd,nome,strlen(nome));
				write(fd,"\n",strlen("\n"));
				write(fd,"Idade: ",strlen("Idade: "));
				write(fd,ids,strlen(ids));
				write(fd,"\n",strlen("\n"));
		//ssize_t res2 = write(fd,&idade,sizeof(idade));
		close(fd);
		//free(nome);
		return 0;
	}