#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>

volatile int a = 0;

int count = 0;

static pthread_mutex_t mutexLock;

void* char_print (void* parameters)
{
	while(1)
	{
		if (count!=a)
		{
			pthread_mutex_lock(&mutexLock);
			printf("%d\n",count);
			a=count;
			pthread_mutex_unlock(&mutexLock);
			
		}
	}	
	return NULL;
}
int main ()
{
	pthread_t thread1_id;
	pthread_mutex_init(&mutexLock, NULL);
	pthread_create(&thread1_id, NULL, &char_print, NULL);

	for (int i = 0; i<10; i++)
	{
		pthread_mutex_lock(&mutexLock);
		count++;
		pthread_mutex_unlock(&mutexLock);
		sleep(1);
	}

	pthread_mutex_destroy(&mutexLock);

	return 0;
}








