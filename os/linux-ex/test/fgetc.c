/*************************************************************************
	> File Name: fgetc.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年04月07日 星期日 09时09分03秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	FILE	*in;
	int ch;

	in = fopen("xsize.c", "r");
	while ((ch = fgetc(in)) != EOF)
		printf("%c", ch);
	printf("EOF = %d\n", EOF);
	printf("Most EOF = %d\n", (EOF & 0x0000ff00) >> 8);
	return 0;
}
