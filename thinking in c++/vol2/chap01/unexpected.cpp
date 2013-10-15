/*************************************************************************
	> File Name: unexpected.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 10时26分23秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

class Up { };
class Fit { };

void fun(int i) throw(Up, Fit, bad_exception)
{
	switch (i) {
		case 1: 
			throw Up();
			break;
		case 2:
			throw Fit();
		default:
			throw 3;
	}
}

void new_unexpected()
{
	cout << "In new_unexpected" << endl;
	exit(0);
}

void (*f)() = set_unexpected(new_unexpected);

int main()
{
	for (int i = 1; i <= 3; i ++) {
		try {
			fun(i);
		} catch (Up &) {
			cout << "Catch Up() " << endl;
		} catch (Fit &) {
			cout << "Catch Fit() " << endl;
		} catch (bad_exception &) {
			cout << "Catch bad_exception() " << endl;
		}
	}
	return 0;
}
