/*************************************************************************
	> File Name: Nojump.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  3:33:50 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X {
	public:
		X();
};

X::X()
{
}

void
f(int i)
{
	if (i < 10) {
	//	goto jump1;
	}
	X x1;

jump1:
	switch(i) {
		case 1:
			X x2;
			break;
	//	case 2:
			X x3;
			break;
	}
}

int 
main(void)
{
	f(9);
	f(11);
	return 0;
}
