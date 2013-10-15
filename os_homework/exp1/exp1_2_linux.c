/*************************************************************************
	> File Name: exp1_2.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年05月08日 星期三 23时16分40秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *find_prime(void *arg)
{
	int num = atoi((char *)arg);
	int i, j, flag;

	
	printf("In thread(tid = %u): ", (unsigned)pthread_self());
	if (num == 1) {
			printf("1 is neither a primer number, nor a composite number!");
		goto bad;
	}
	printf("The primers (<= %d): ", num);
	for (i = 2; i <= num; i ++) {
		flag = 0;
		for (j = 2; j * j <= i; j ++) 
			if (i % j == 0)
				flag = 1;
		if (!flag)
			printf("%d ", i);
	}

bad:
	printf("\n");
	pthread_exit(0);
}
int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr, "Usage: %s <number>\n", argv[0]);
		exit(0);
	}
	pthread_t	pid;

	if (pthread_create(&pid, NULL, find_prime, argv[1]))
		fprintf(stderr, "Thread create error!\n");
	pthread_join(pid, NULL);
	exit(0);
}
