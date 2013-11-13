/*************************************************************************
	> File Name: map.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Oct 24, 2013  3:11:17 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<string, int> a;
	a.insert(pair<string, int>("wei", 5));

	cout << a["wei"] << endl;
	cout << a[0].first << endl;
	cout << a[0].second <<< endl;

	return 0;
}


