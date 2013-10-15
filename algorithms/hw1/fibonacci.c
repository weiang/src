/*************************************************************************
	> File Name: fibonacci.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月07日 星期一 15时47分59秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <time.h>
/*
 * Recursive implementation of fibonacci function
 * Return the nth fibonacci number
 */

long fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;	// Terminal condition

	return fibonacci(n - 1) + fibonacci(n - 2);	// Recursively calling fibonacci function of n - 1 to get nth fibonacci number
}

/*
 * Analyse the running time of fibonacci function with arguement n
 * Return the running time of the function, measured in ms
 */

double analysis(int n) 
{
	clock_t start_time;	// Record the system time when fibonacci function is called
	clock_t end_time;	// Record the system time when fibonacci function returns
	double runtime;
	long result;

	printf("Start to call fibonacci(%d) ...\n", n);
	start_time = clock();	// Get system time 
	result = fibonacci(n);
	end_time = clock();	// Record system time when ended
	printf("Return from fibonacci(%d)\n", n);
	printf("fibonacci(%d) = %ld\n", n, result);
	runtime = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

	printf("Running time of fibonacci(%d): ", n);
	printf("%f\n", runtime);
	return runtime;
}

int main(void)
{
	int n = 1;
	double ms; // Record running time
	
	FILE *o;
	o = fopen("output", "w+");

	do {
		ms = analysis(n);
		fprintf(o, "%d %lf\n", n, ms);
		n ++;
	} while (n != 53);

	return 0;
}
