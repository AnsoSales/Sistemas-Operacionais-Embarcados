1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?
ps -ef – Lista os processos que estão sendo executados agora. (Outro comando semelhante é ps aux)

(b) Mostrar os processos de um usuário?
ps -f -u user1,user2 – Exibirá todos os processos com base no UID fornecido (ID do usuário ou nome de usuário).

(c) Ordenar todos os processos de acordo com o uso da CPU?
ps aux --sort=-pcpu,+pmem – Exibirá processos que consumam a maior parte da CPU.

(d) Mostrar a quanto tempo cada processo está rodando?
ps
TIME- Tempo que o processo utilizou da CPU (horas:minutos:segundos)

2. De onde vem o nome `fork()`?

  Essa é a ideia de um fork: O(s) desenvolvedor(es) pega(m) a cópia do código fonte do software e inicia(m) um projeto
independente em cima do que obtiveram, vindo a criar um software separado. Desta forma existem dois projetos semelhantes 
em propósito, porém, cada um possuindo certas características próprias.
  O fork é uma função que é uma chamada de sistema. Ou seja, ela invoca o sistema operacional para fazer alguma tarefa que
o usuário não pode.No caso, o fork é usado para criar um novo processo em sistemas do tipo Unix, e isso só pode ser feito via fork.
Quando criamos um processo por meio do fork, dizemos que esse novo processo é o filho, e processo pai é aquele que usou o fork.
  Por exemplo, suponha que você programou um software em C, e nele usou a chamada fork().
Esse programa em C, executando, é o processo pai.
  Quando usamos o fork, será criado o processo filho, que será idêntico ao pai, inclusive tendo as mesmas variáveis, registros, descritores
de arquivos etc.Ou seja, o processo filho é uma cópia do pai, exatamente igual.
  Porém, é uma cópia, e como tal, depois de criado o processo filho, ele vai ser executado e o que acontece em um processo não ocorre no outro, 
são processos distintos agora, cada um seguindo seu rumo, onde é possível mudar o valor de uma variável em um e isso não irá alterar o valor 
desta variável no outro processo, por exemplo.


3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?
É uma função da biblioteca stdlib.h que permite executar um comando dentro de um proframa, criando
um sub-processo(processo filho).
Afunção system retorna em sua saída o status do comando no shell. Se o shell não puder ser executado,
o system() retorna o valor 127; se um outro erro ocorre, a função retorna -1.
O uso do system não é recomendado na maioria dos casos. É simples mas dá brechas a falhas de execução
pois depende muito do sistema.

(b) `fork()` e `exec()`?
No Unix não há meio para que um processo crie outro somente mandando executá-lo diretamente. Não há
função que crie e execute um novo processo em um único passo.
Para isso utiliza-se a função 'fork()'que ccria uma cópia do processo atual e em seguida a função 'exec()' que substitui o conteúdo do novo processo por um novo programa.

4. É possível utilizar o `exec()` sem executar o `fork()` antes?
Na chamada de uma função exec(), existe um recobrimento do segmento de instruções do processo que chama a função. Desta forma, não existe retorno de um exec() cuja execução seja correta (o endereço de retorno desaparece). Em outras palavras, o processo que chama a função exec() morre.

O código do processo que chama uma função exec() será sempre destruído, e desta forma, não existe muito sentido em utilizá-la sem que ela esteja associada a uma primitiva fork().

5. Quais são as características básicas das seguintes funções:

(a) `execp()` = aceita que o nome ou procura do programa esteja no current path (pasta atual);

(b) `execv()` =  aceita que a lista de argumentos do novo programa seja nula.
```c
int execv(const char *path, char *const argv[]);
```
(c) `exece()` = aceita um argumento adicional.
(d) `execvp()`= usando esse comando, o processo filho não precisa rodar o mesmo programa que o processo pai.
```c
int execvp (const char *file, char *const argv[]);
```

(e) `execve()` = aceita que a lista de argumentos do novo programa seja nula e um argumento adicional.

(f) `execle()`= aceita em sua lista de argumentos a utilização de mecanismos var args em linguagem C e um argumento adicional. 