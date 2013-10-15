/*************************************************************************
	> File Name: exp3.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Mon, May 20, 2013  8:42:14 PM
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	pid_t	pid;
	char *arg1[] = {"./deadlock", NULL};
//	char *arg2[] = {"./semaphore", NULL};
	char *arg3[] = {"./monitor", NULL};

	if ((pid = fork()) == 0) {
		execv(arg1[0], arg1);
		exit(0);
	}

//	if ((pid = fork()) == 0) {
//		execv(arg2[0], arg2);
//		exit(0);
//	}

	if ((pid = fork()) == 0) {
		execv(arg3[1], arg3);
		exit(0);
	}
	

	return 0;
}



