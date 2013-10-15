/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月22日 星期二 23时49分49秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "url.h"

using namespace std;

void show_result(const vector<string>& s)
{
	for (vector<string>::const_iterator i = s.begin(); i != s.end(); i ++)
		cout << *i << endl;
}

int main()
{
	string	x;
	while (getline(cin, x)) {
		vector<string>	result;
		result = find_urls(x);
		show_result(result);
	}
	return 0;
}
