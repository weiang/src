/*************************************************************************
	> File Name: 5.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 16时57分58秒
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
		string s = "a string";
		{
			string x = s + ", really";
			cout << s << endl;
		}
		cout << x << endl;
	}
	return 0;
}
