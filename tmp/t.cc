/*************************************************************************
	> File Name: t.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jun 27, 2013  9:45:51 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	char ch, str[20];
	cin.getline(str, 5);
	cout << "Flag1: " << cin.good() << endl;
//	cin.clear();
//	cout << "Flag2: " << cin.good() << endl;

	cin >> ch;
	cout << "Str: " << str << endl;
	cout << "Ch: " << (int)ch << endl;
	return 0;
}
