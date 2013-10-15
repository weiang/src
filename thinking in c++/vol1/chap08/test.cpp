/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  2:48:58 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
	public:
		A(int a) : i(a) { }

		void fun() {
			i = 1;
		};

		void fun2()  volatile {
			cout << "In fun2!" << endl;
		};

	private:
		int i;
};

int 
main(void)
{
	volatile A a(2);
//	a.fun();
	a.fun2();
	return 0;
}
