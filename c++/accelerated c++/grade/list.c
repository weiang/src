/*************************************************************************
	> File Name: list.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月22日 星期二 14时16分57秒
    > Describition: 
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void produce(int n)
{
	FILE	*o;

	o = fopen("out", "w");
	
	srand(time(NULL));
	for (int i = 0; i < n; i ++) {
		char	name[BUFSIZ];
		int len = rand() % 10 + 1;
		for (int j = 0; j < len; j ++) {
			int	tmp = rand() % 26;
			if (j == 0)
				tmp += 'A';
			else
				tmp += 'a';
			name[j] = tmp;
		}
		fprintf(o, "%s", name);
		int midterm = rand() % 100 + 1;
		int final = rand() % 100 + 1;
		int l_homework = rand() % 20 + 1;
		fprintf(o, " %d %d", midterm, final);
		for (int j = 0; j < l_homework; j ++)
			fprintf(o, " %d", rand() % 100 + 1);
		fprintf(o, "\n");
	}
	fclose(o);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		produce(100);
	else 
		produce(atoi(argv[1]));
	return 0;
}

