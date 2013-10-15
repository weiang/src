/*************************************************************************
	> File Name: thread_create.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年02月18日 星期一 13时04分08秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

int sum;

void *runner(void *param);

int main(void)
{
	int i = 10;
	pthread_t	tid;
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, &i);
	pthread_join(tid, NULL);
	printf("sum = %d\n", sum);
	return 0;
}

void *runner(void *param)
{
	int upper = *(int *)param;
	int i;
	sum = 0;

	for (i = 1; i <= upper; i ++)
		sum += i;
	pthread_exit(0);
}
