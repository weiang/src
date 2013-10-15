/*************************************************************************
	> File Name: 6_7.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  4:55:41 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	double a[10] = {0, 1, 2};
	for (int i = 0; i < 10; i ++)
		cout << a[i] << " ";
	cout << endl;

	double b[] = {0, 1, 2};
	for (int i = 0; i < sizeof b / sizeof *b; i ++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}
