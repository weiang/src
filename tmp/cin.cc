/*************************************************************************
	> File Name: cin.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jun 27, 2013  9:41:04 AM
    > Describition: 
 ************************************************************************/
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	while (1) {
		int i = 0;
		cout << "Please input a number: ";
		cin >> i;
		cin.clear();
//		cin.sync();
		fflush(stdin);
		cout << i << endl;
	}
	return 0;
}
