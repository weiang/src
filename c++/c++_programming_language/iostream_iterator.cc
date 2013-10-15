/*************************************************************************
	> File Name: iostream_iterator.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年02月17日 星期日 23时30分26秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	string from, to;
	cin >> from >> to;

	ifstream is(from.c_str());
	istream_iterator<string> ii(is);
	 istream_iterator<string> d;
	
	vector<string> vs(ii, d);
	sort(vs.begin(), vs.end());

	ofstream os(to.c_str());
	ostream_iterator<string> oo(os, "\n");
	unique_copy(vs.begin(), vs.end(), oo);

	return is.eof() && os;
}
