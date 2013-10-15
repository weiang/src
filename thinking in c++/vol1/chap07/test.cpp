/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  1:55:09 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	char *a = "hello, world!\n";
	
	cout << static_cast<string>(a);
	return 0;
}
