/*************************************************************************
	> File Name: 1.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月27日 星期四 12时57分36秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int
main(void)
{
	string::size_type maxlen = 1;
	string a = "Hello";

	max(a.size(), maxlen);
	return 0;
}
