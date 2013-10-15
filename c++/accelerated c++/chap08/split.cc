/*************************************************************************
	> File Name: split.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月24日 星期四 22时08分08秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

template <class os>
void split(const string& s, os o)
{
	string::const_iterator it = s.begin();

	while(it != s.end()) {
		it = find_if(it, s.end(), not_space);
		if (it != s.end()) {
			string::const_iterator	j = find_if(it, s.end(), space);
			*o ++ = string(it, j);
			it = j;
		}
	}
}


int main()
{
	string s;
	while (getline(cin, s)) {
		split(s, ostream_iterator<string>(cout, "\n"));
	}
	return 0;
}
