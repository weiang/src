#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>


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

sem_t sem;
pthread_mutex_t	forks[PHI_NUM];

void *philosopher(void *pi)
{
	int who = *(int *)pi;
	while (1) {
		thinking(who);
		sem_wait(&sem);
		
		if (who % 2) {
			pthread_mutex_lock(&forks[who % PHI_NUM]);
	//		printf("%d got fork %d\n", who, who);
			pthread_mutex_lock(&forks[(who + 1) % PHI_NUM]);
	//		printf("%d got fork %d\n", who, (who + 1) % PHI_NUM);
		}
		else {
			pthread_mutex_lock(&forks[(who + 1) % PHI_NUM]);
			pthread_mutex_lock(&forks[who]);
		}
		sem_post(&sem);
		eating(who);
		pthread_mutex_unlock(&forks[who % PHI_NUM]);
		printf("%d return fork %d\n", who, who);
		pthread_mutex_unlock(&forks[who % PHI_NUM]);
		printf("%d return fork %d\n", who, (1 + who) % PHI_NUM);
	}
}

int philo_num[PHI_NUM];

int main()
{
	int i;
	pthread_t tid[PHI_NUM];
	pthread_attr_t	attr[PHI_NUM];

	sem_init(&sem, 0, 4);
	for (i = 0; i < PHI_NUM; i ++) {
		pthread_mutex_init(&forks[i], NULL);
		philo_num[i] = i;
	}

	printf("Using Semaphore\n");
	for (i = 0; i < PHI_NUM; i ++) {
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], philosopher, (void *)(philo_num + i));
	}
		
	while(1)
		;
	return 0;
}
