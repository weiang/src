/*************************************************************************
	> File Name: 5_5.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  4:38:42 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A;

class C {
	public:
		void fun(A *ptr);
};

class A {
	private: 
		int a;

	friend class B;
	friend void C::fun(A *);
};

class B {
	public:
		void bf(A *ptr);
};

void
B::bf(A *ptr)
{
	cout << "In B: " << ptr -> a << endl;
}

void
C::fun(A *ptr)
{
	cout << "In C: " << ptr -> a << endl;
}

int
main(void)
{
	A aa;
	B bb;
	C cc;

	bb.bf(&aa);
	cc.fun(&aa);
	return 0;
}




