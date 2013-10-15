/*************************************************************************
	> File Name: thread_sch.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年02月18日 星期一 12时49分30秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

#define NUM 5

void *runner(void *);

int main(void)
{
	int i, scope;
	pthread_attr_t attr;
	pthread_t	tid[NUM];

	pthread_attr_init(&attr);
	if (pthread_attr_getscope(&attr, &scope) != 0) {
		fprintf(stdout, "Unable to get scheduling scope\n");
		return 1;
	}
	else if (scope == PTHREAD_SCOPE_SYSTEM)
		printf("PTHREAD_SCOPE_SYSTEM\n");
	else if (scope == PTHREAD_SCOPE_PROCESS)
		printf("PTHREAD_SCOPE_PROCESS\n");
	else {
		fprintf(stderr, "Illegal scope value\n");
		return 1;
	}

	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);

	for (i = 0; i < NUM; i ++) 
		pthread_create(&tid[i], &attr, runner, NULL);
	for (i = 0; i < NUM; i ++)
		pthread_join(tid[i], NULL);
	return 0;
}

void *runner(void *param)
{
	pthread_attr_t	a;
	int s;

	printf("Hello\n");
	pthread_attr_getscope(&a, &s);
	if (s == PTHREAD_SCOPE_SYSTEM)
		printf("Set succeed!\n");
	else 
		printf("Set failed\n");
	pthread_exit(0);
}
