/*************************************************************************
	> File Name: 5.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 17时06分45秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	cout << "Please enter square size: ";
	int size;
	cin >> size;

	string first;
	for (int i = 0; i != size; i ++)
		first += "* ";
	first += '*';

	string next(2 * size - 1, ' ');
	next = '*' + next + '*';

	for (int i = 0; i != size + 1; i ++) {
		if (i == 0 || i == size)
			cout << first << endl;
		else 
			cout << next << endl;
	}
	return 0;
}
