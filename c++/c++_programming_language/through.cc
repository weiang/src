/*************************************************************************
	> File Name: through.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年02月18日 星期一 00时00分13秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

map<const string, int> histogram;
void record(const string& s)
{
	histogram[s] ++;
}

void print(const pair<const string, int> p)
{
	cout << p.first << ' ' << p.second << '\n';
}

int main(void)
{
	istream_iterator<string> ii(cin);
	istream_iterator<string> eos;

	for_each(ii, eos, record);
	for_each(histogram.begin(), histogram.end(), print);
	return 0;
}
