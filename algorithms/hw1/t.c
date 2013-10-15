/*************************************************************************
	> File Name: t.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月07日 星期一 19时17分22秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <time.h>

long f(int n)
{
	if ( n == 1  || n == 2)
		return 1;
	else 
		return f(n - 1) + f(n - 2);
}

int main()
{
	int n;
	time_t start;
	time_t end;

	while (1) {
		if (feof(stdin)) 
			break;
		scanf("%d", &n);
		time(&start);
		f(n);
		time(&end);
		printf("%ld\n", (long)end - (long)start);
	}
	return 0;
}
