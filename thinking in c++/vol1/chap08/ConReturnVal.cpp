/*************************************************************************
	> File Name: ConReturnVal.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  9:41:41 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X {
		int i;
	public:
		X(int ii = 0);
		void modify();
		void print();
};

X::X(int ii)
{
	i = ii;
}

void 
X::modify()
{
	i ++;
}

void
X::print()
{
	cout << i << endl;
}


X 
f5()
{
	return X();
}

const X
f6()
{
	return X();
}

void 
f7(X& x)
{
	x.modify();
}

int
main(void)
{
	(f5() = X(2)).print();
//	f7(f5());
	f6().modify();
	f6() = X(2);
	f7(f6());

	return 0;
}


