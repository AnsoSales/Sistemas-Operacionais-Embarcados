Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.
```C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

	int main (int argc, const char **argv)
	{
		int fd;
		char *nome=(char*)malloc(100*sizeof(char));
		fd = open(argv[2],O_RDWR | O_CREAT);
		ssize_t res = write(fd,argv[1],strlen(argv[1]));
		close(fd);
		return 0;
	}
```
2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
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
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

	int main (int argc, const char **argv)
	{
		int fd;
		char *nome=(char*)malloc(100*sizeof(char));
		strcat(nome,argv[1]);
		strcat(nome,".txt");
		fd = open(nome,O_RDWR | O_CREAT);
		write(fd,"Nome: ",strlen("Nome: "));
		write(fd,argv[1],strlen(argv[1]));
		write(fd,"\n",strlen("\n"));
		write(fd,"Idade: ",strlen("Idade: "));
		write(fd,argv[2],strlen(argv[2]));
		write(fd,"\n",sizeof("\n"));
		close(fd);
		return 0;
	}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```C
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
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```C
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
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

```C
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
```
7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
