/*************************************************************************
	> File Name: assert.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月03日 星期六 12时57分28秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <cstdlib>

#ifndef NDEBUG
#define NDEBUG
#endif

using namespace std;

int main()
{
	assert(0);
	return EXIT_SUCCESS;
}
