Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.
```c
#include <stdio.h>

int main(){

	printf("Ola mundo!");
return 0;
}
```
2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```C
#include <stdio.h>
#include <stdlib.h>

int main(){
	char a[22];
	printf("Digite seu nome:\n");
	scanf("%[^\n]s", a);
	printf("Ola %s \n", a);

return 0;
}
```

3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
	Saiu o nome inserido da mesma forma que foi digitado.

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
	Saiu o nome com as aspas, por exemplo "eu mesmo".

(c) Se é usado um pipe. Por exemplo:
	Ele não pediu o nome do usuário, só colocou o nome colocado com o pipe. 

(d) Se é usado um pipe com mais de um nome. Por exemplo:
	Ele não pediu o nome do usuário de novo, só colocou o nome com espaço colocado com o pipe. 

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
	Ele não pediu o nome do usuário de novo, só colocou o nome com espaço, mas sem aspas, colocado com o pipe. 

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
	Ele não deixa o usuario colocar o nome e escreve na tela o que foi escrito no arquivo txt.

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```C
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;

		printf("Ola %s %s \n", argv[1], argv[2]);
		
	
	return 0;
}
```
5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
	Saiu o nome inserido da mesma forma que foi digitado.

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
	Aparece: 'palavra inserida' null porque conta como um vetor só.

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```	
	Ele não reconhece a palavra colocada antes do pipe.

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
	Ele não reconhece a palavra colocada antes do pipe.
	

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
	Ele não reconhece a palavra colocada antes do pipe.

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt>
```
	Ele escreve na tela apenas "Ola (null)"
	

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```
```C
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;

	printf("Ola %s\n", argv[1]);
	printf("numero de entradas = %d\n",argc);

return 0;
}
```

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```

```C
#include <stdio.h>
int main(int argc, char **argv)
{
	int i;
	for(j = 1; j <= argc ; j++){
		printf(" %s ", argv[i]);		
	}
	printf("\n");
	return 0;
}
	
``` 

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.
A função abaixo está no arquivo.h e foi chamada por um arquivo.c

```C
int minha(char *str)
{
    int total=0;

    while( str[total] != '\0')
        total++;

    return total;
}
```

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```
```C
#include <stdio.h>
#include <string.h>
#include "num_caracs.h"
int main(int argc, char **argv){
	char str[20];
	int total;
	for(int i = 0; i < argc; i++){
	printf("Argumento: %s\n",argv[i]);
	total = minha(argv[i]);
	printf("numero de caracteres: %d\n",total);
	}
	
return 0;
}
```


10. Crie um Makefile para a questão anterior.

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```
```C
#include <stdio.h>
#include <string.h>
#include "num_caracs.h"
int main(){
	char str[20];
	int total;
	scanf("%[^\n]s", str);
	total = minha(str);
	printf("Total de caracteres de entrada: %d\n", total);
return 0;
}
```


12. Crie um Makefile para a questão anterior.
