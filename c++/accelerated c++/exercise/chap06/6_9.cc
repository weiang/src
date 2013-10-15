/*************************************************************************
	> File Name: 6_9.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 19时08分22秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	vector<string> a;
	
	string c;
	while (cin >> c) {
		if (c.size() <= 1)
			break;
		else 
			a.push_back(c);
	}

	string	b;
	b = accumulate(a.begin(), a.end(), b);
	cout << b << endl;
	return 0;
}

