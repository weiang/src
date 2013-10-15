/*************************************************************************
	> File Name: exp1.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年05月08日 星期三 22时50分29秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	pid_t child;
	time_t	timer;
	struct tm	*tblock;
	char *argv[] = {"date",
					 NULL };

	if ((child = fork()) == 0) {
		printf("From Child process(pid = %d): ", getpid());
		fflush(stdout);
		execv("/bin/date", argv);
		exit(0);
	}
	
	wait();
	timer = time(NULL);
	tblock = localtime(&timer);
	printf("From Parent process: %s", asctime(tblock));
	printf("Parent process id: %d, Child process id: %d\n", getpid(), child);
}
