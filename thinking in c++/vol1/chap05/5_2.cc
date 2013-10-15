/*************************************************************************
	> File Name: 5_2.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  4:15:29 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Lib {
	string s[3];
};

int
main(void)
{
	Lib x;

	x.s[0] = "weiang";
	x.s[1] = "Hello, world!";
	x.s[2] = "Upang";

	cout << x.s[0] << x.s[1] << x.s[2] << endl;
	return 0;
}
