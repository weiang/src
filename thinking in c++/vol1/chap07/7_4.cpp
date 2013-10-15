/*************************************************************************
	> File Name: 7_4.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  2:50:40 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
	public:
		/*
		void fun();
		void fun(int);
		void fun(int, int);
		*/
		void fun(int = 0, int = 0, int = 0);
};

/*
void 
A::fun()
{
}

void 
A::fun(int a)
{
	cout << a << endl;
}

void 
A::fun(int a, int b)
{
	cout << a << endl
		<< b << endl;
}
*/

void 
A::fun(int a, int b, int c)
{
	cout << a << endl
		<< b << endl
		<< c << endl;
}

int
main()
{
	A m;
	m.fun();
	m.fun(1);
	m.fun(1, 2);
	m.fun(1, 2, 3);
	return 0;
}

