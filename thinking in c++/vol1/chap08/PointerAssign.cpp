/*************************************************************************
	> File Name: PointerAssign.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013 11:14:06 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	const int e = 2;
	int *w = (int *)&e;

	*w = 3;
	cout << "e = " << e << endl;
	cout << "*w = " << *w << endl;
	cout << &e << " " << w << endl;
	cout << e << endl;
	return 0;
}


