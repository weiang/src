/*************************************************************************
	> File Name: test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年03月20日 星期三 08时46分34秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	std::vector<int> vec;

	vec.push_back(1);
	const vector<int>::iterator itor = vec.begin();

	*itor = 10;
	return 0;
}
