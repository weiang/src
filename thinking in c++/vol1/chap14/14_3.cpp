/*************************************************************************
	> File Name: 14_3.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013 10:59:25 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A { 
	public:
		A() { cout << "A() " << endl; }
		~A() { cout << "~A() " << endl; }

};
class B : public A { 
	public:
		B() { cout << "B() " << endl; }
		~B() { cout << "~B() " << endl; }
};

class C : public B {
	public:
		C() { cout << "C() " << endl; }
		~C() { cout << "~C() " << endl; }
};

int 
main(void)
{
	C a;
	return 0;
}
