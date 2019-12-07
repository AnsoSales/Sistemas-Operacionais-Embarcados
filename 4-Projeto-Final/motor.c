#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <dirent.h>
#include <string.h>
#include <wiringPi.h>
#define TOKEN "870108773:AAG75TI6yFPTl3zSEWxZAp6M-F-sDVHpjPQ"
#define MOTO1 0
#define MOTO2 2

#define BASE 64
#define Address 0x48
#define A0 BASE



	int main (int argc, const char **argv)
	{
	wiringPiSetup();
	pinMode(MOTO1, OUTPUT);	
		pinMode(MOTO2, OUTPUT);	
	pid_t filhote;
		
		filhote = fork();
		if (filhote == 0)
		{
			
		digitalWrite(MOTO1, HIGH);
                usleep(8000000);
                digitalWrite(MOTO1, LOW);
		usleep(8000000);
		}else
		{
		digitalWrite(MOTO2, HIGH);
               usleep(8000000);
                digitalWrite(MOTO2, LOW);
		{return -1;}

		}
	return 0;
	}
