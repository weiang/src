/*************************************************************************
	> File Name: 6.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 17时00分33秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int
main(void)
{
	cout << "What's your name?";
	string name;
	cin >> name;
	cout << "Hello," << name 
		 << endl << "And what is yours?";
	cin >> name;
	cout << "Hello," << name 
		 << "; Nice to meet you too!" << endl;

	return 0;
}
