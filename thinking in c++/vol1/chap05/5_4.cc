/*************************************************************************
	> File Name: 5_4.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  4:22:17 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class B;

class A {
	private:
		B *ptr;
	public:
		void fun(B *);
};

class B {
	private:
		A *ptr;
	public:
		void fun(A *);
};

void 
A::fun(B *p)
{
	ptr = p;
}

void
B::fun(A *p)
{
	ptr = p;
}

int
main(void)
{
	A a;
	B b;

	a.fun(&b);
	b.fun(&a);
	return 0;
}
