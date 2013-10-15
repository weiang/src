/*************************************************************************
	> File Name: sizes.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013 12:01:27 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class x { };

class y {
	int a;
};

class z {
	int a;
	virtual void fun() { }
};

class t {
	void fun() { }
};

int 
main(void)
{
	cout << sizeof(x) << endl;
	cout << sizeof(y) << endl;
	cout << sizeof(z) << endl;
	cout << sizeof(t) << endl;

	return 0;
}


