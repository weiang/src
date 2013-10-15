/*************************************************************************
	> File Name: a.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  7:09:49 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
		static const int size;
		int a[size];
};

const int A::size = 10;


int 
main(void)
{
	A b;
}
