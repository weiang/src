/*************************************************************************
	> File Name: grammer_test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 21时58分13秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "grammer.h"

using namespace std;

int main()
{
	vector<string>	ret;

	ret = gen_sentence(read_grammer(cin));

	vector<string>::const_iterator it = ret.begin();
	if (!ret.empty()) {
		cout << *it;
		++ it;
	}

	while (it != ret.end()) {
		cout << " " << *it;
		++ it;
	}
	cout << endl;
	return 0;
}

