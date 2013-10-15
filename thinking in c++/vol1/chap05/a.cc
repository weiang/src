/*************************************************************************
	> File Name: a.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  4:12:41 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
	private:
		int a;
	protected:
		int b;
	public:
		int c;
};

int 
main(void)
{
	A d;

	d.a = 1;
	d.b = 2;
	d.c = 3;
	return 0;
}
