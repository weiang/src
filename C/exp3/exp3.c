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

	if ((pid = fork()) == 0) {
		exec();
	}

	if ((pid = fork()) == 0) {
		exec();
	}

	if ((pid = fork()) == 0) {
	}

	return 0;
}



