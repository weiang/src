/*************************************************************************
	> File Name: 3.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 16时54分43秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int 
main(void)
{
	{
		const std::string s = "a string";
		std::cout << s << endl;
	}

	{
		const std::string s = "another string";
		cout << s << endl;
	}

	return 0;
}

