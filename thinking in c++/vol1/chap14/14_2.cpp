/*************************************************************************
	> File Name: 14_2.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013 10:57:18 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A { };
class B { };
class C : public A {
	B b;
};


int
main()
{
	C c;
	return 0;
}
