/*************************************************************************
	> File Name: 4_4.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 24, 2013  5:55:50 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct A {
	int a;
	void f1(int);
	void f2(void);
};

int 
main(void)
{
	A b;
	b.a = 1;
	b.f2();
	b.f1(2);
	b.f2();
	return 0;
}

void 
A::f1(int c)
{
	a = c;
}

void 
A::f2(void)
{
	cout << "a = " << a << endl;
}


