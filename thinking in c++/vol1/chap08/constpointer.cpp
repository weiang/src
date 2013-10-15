/*************************************************************************
	> File Name: constpointer.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  9:39:19 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int * const w()
{
static int i;
	return &i;
}

int
main(void)
{
	const int *cip = w();
	return 0;
}
