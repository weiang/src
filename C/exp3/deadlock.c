#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


#define EATING_TIME		3	
#define THINKING_TIME	3	
#define PHI_NUM	5

void thinking(int i)
{
	printf("Philosopher %d is THINKING!\n", i);
	fflush(stdout);
	sleep(rand() % THINKING_TIME); 
}

void eating(int i)
{
	printf("Philosopher %d is EATING!\n", i);
	fflush(stdout);
	sleep(EATING_TIME);
}

pthread_mutex_t	forks[PHI_NUM];

void *philosopher(void *pi)
{
	int who = *(int *)pi;
	
	while (1) {
		pthread_mutex_lock(&forks[who % PHI_NUM]);
	//	printf("%d got fork %d\n", who, who);
		pthread_mutex_lock(&forks[(who + 1) % PHI_NUM]);
	//	printf("%d got fork %d\n", who, (who + 1) % PHI_NUM);
		eating(who);
		pthread_mutex_unlock(&forks[who % PHI_NUM]);
	//	printf("%d return fork %d\n", who, who);
		pthread_mutex_unlock(&forks[who % PHI_NUM]);
	//	printf("%d return fork %d\n", who, (1 + who) % PHI_NUM);
		thinking(who);
	}
}

	
int main()
{
	int i;
	pthread_t tid[PHI_NUM];
	pthread_attr_t	attr[PHI_NUM];

	for (i = 0; i < PHI_NUM; i ++) {
		pthread_mutex_init(&forks[i], NULL);
	}

	printf("Deadlock may happen\n");
	for (i = 0; i < PHI_NUM; i ++) {
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], philosopher, &i);
	}
		
	while(1)
		;
	return 0;
}
