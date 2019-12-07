1. Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi.

```C
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#define SAIDA 7

void sqwv(int frequencia){
	
	int tempo = 1000000;
	while(1){
		digitalWrite(SAIDA, HIGH);
		usleep(tempo/2);
		digitalWrite(SAIDA, LOW);
		usleep(tempo/2);
	}

}
```
2. Generalize o código acima para qualquer frequência possível.
```C

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#define SAIDA 7

void sqwv(int frequencia){
	
	int tempo = 1000000;
	while(1){
		digitalWrite(SAIDA, HIGH);
		usleep(tempo/2);
		digitalWrite(SAIDA, LOW);
		usleep(tempo/2);
	}

}
```
3. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai lê um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <wiringPi.h>





int main()
{
	
	WiringPiSetup();
	pinMode(SAIDA, OUTPUT);
	pinMode(ENTRADA, INPUT);
	pullUpDnControl(ENTRADA, PUD_UP);
	signal(SIGUSR1, muda_freq);
		
	int pid;
	pid = fork();
	// Codigo do filho
	int tempo = 1000000;
	if(pid == 0)
	{	int meio_periodo = 1000000/2;
		while(1){
		digitalWrite(SAIDA, HIGH);
		usleep(tempo/2);
		digitalWrite(SAIDA, LOW);
		usleep(tempo/2);
		}
	}
	else
	{
		while(1)
		{
		while(digitalRead(ENTRADA)>0);
		kill(pid, SIGUSR1);
		while(digitalRead(ENTRADA)==0);
		usleep(300000);
		}
	}

}
```