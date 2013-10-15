/*************************************************************************
	> File Name: xsize.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年04月07日 星期日 08时58分20秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	unsigned char uchar = 0xff;
	signed char schar = 0xff;

	int a = (int) uchar;
	int b = (int) schar;

	printf(" a = %d, b = %d\n", a, b);
	return 0;
}

