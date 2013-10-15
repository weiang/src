/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013  9:25:08 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class a {
	int i, j, k;
};

int 
main(void)
{
	a b;
	a *m = &b;
	a& n = b;

	cout << sizeof(m) << endl;
	cout << sizeof(a&) << endl;
	cout << sizeof(b) << endl;
	return 0;
}

