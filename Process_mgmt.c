#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void *core(void *arg);

int main(void) {
    pthread_t core1;	// Thread representing core #1
    pthread_t core2;	// Thread representing core #2
	int i = 0;

	pthread_create(&core1,NULL,core,"foo");
	pthread_create(&core2,NULL,core,"bar");
	
	while(i < 100)
	{
		usleep(1);
		printf("main is running...\n");
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(core1,NULL);
	pthread_join(core2,NULL);

	return 0;
}

void *core(void *arg) {
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 110 )
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}
