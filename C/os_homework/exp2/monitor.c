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

int forks[PHI_NUM];
pthread_mutex_t	mutex;
pthread_cond_t	cond;

void pickup_forks(int who)
{
	pthread_mutex_lock(&mutex);
	while (forks[who] != 0)
		pthread_cond_wait(&cond, &mutex);
	forks[who] = 1;
	while (forks[(who + 1) % PHI_NUM] != 0)
		pthread_cond_wait(&cond, &mutex);
	forks[(who + 1) % PHI_NUM] = 1;
	pthread_mutex_unlock(&mutex);
}

void return_forks(int who)
{
	pthread_mutex_lock(&mutex);
	if (forks[who] == 1) 
		pthread_cond_signal(&cond);
	forks[who] = 0;

	if(forks[(who + 1) % PHI_NUM] == 1)
		pthread_cond_signal(&cond);
	forks[(who + 1) % PHI_NUM] = 0;
	pthread_mutex_unlock(&mutex);
}

void *philosopher(void *pi)
{
	int who = *(int *)pi;
	
	while (1) {
		thinking(who);
		pickup_forks(who);
		eating(who);
		return_forks(who);
	}
}

	
int main()
{
	int i;
	pthread_t tid[PHI_NUM];
	pthread_attr_t	attr[PHI_NUM];
	
	
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	for (i = 0; i < PHI_NUM; i ++)
		forks[i] = 0;

	printf("Using Monitor\n");
	for (i = 0; i < PHI_NUM; i ++) {
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], philosopher, &i);
	}
		
	while(1)
		;
	return 0;
}
