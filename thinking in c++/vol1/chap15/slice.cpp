/*************************************************************************
	> File Name: slice.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013  4:40:20 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
	public:
		virtual void print() const = 0 ;
/*		{
			cout << "A::print() " << endl;
		}
*/
};


void
A::print() const 
{
	cout << "A::print() " << endl;
}

class B : public A {
	public:
		void print() const
		{
			cout << "B::print() " << endl;
		}
};

void 
fun(A a)
{
	a.print();
}

int
main(void)
{
	B b;	
	fun(b);
	return 0;
}
