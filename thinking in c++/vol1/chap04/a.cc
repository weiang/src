/*************************************************************************
	> File Name: a.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 24, 2013 10:25:09 PM
    > Describition: 
 ************************************************************************/

#include <stdio.h>

struct weiang {
	void fun(int);
};

void
weiang::fun(int a)
{
	printf("%d\n", a);
}
