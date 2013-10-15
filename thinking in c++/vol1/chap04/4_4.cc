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
};

void f1(A *, int);
void f2(A *);

int 
main(void)
{
	A b;
	b.a = 1;
	f2(&b);
	f1(&b, 2);
	f2(&b);
	return 0;
}

void 
f1(A *b, int c)
{
	b -> a = c;
}

void 
f2(A *b)
{
	cout << "a = " << b -> a << endl;
}


