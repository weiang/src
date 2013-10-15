/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Aug 07, 2013  5:40:40 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "date.h"

using namespace std;

int nPass = 0, nFail = 0;
void test(bool t)
{
	if (t)
		nPass ++;
	else
		nFail ++;
}

int main()
{
	date myday(1951, 10, 1);
	test(myday.get_year() == 1951);
	test(myday.get_month() == 10);
	test(myday.get_day() == 1);

	cout << "Passed: " << nPass << ", Failed: " << nFail << endl;
	return 0;
}
