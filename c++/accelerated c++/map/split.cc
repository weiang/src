/*************************************************************************
	> File Name: split.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月22日 星期二 09时34分13秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(const string& s)
{
	vector<string>	ret;
	typedef	string::size_type	string_size;
	string_size	i = 0;


	while(i != s.size()) {
		while (i != s.size() && isspace(s[i]))
			i ++;
		string_size	j = i;
		while(j != s.size() && !isspace(s[j]))
				j ++;
		if (i != j)
			ret.push_back(s.substr(i, j - i));
		i = j;
	}
	return ret;
}
/*
int main(void)
{
	string	s;
	while(getline(cin, s)) {
		vector<string> result;
		result = split(s);
		for (vector<string>::const_iterator i = result.begin(); i != result.end(); i ++)
			cout << *i << " ";
	}
	return 0;
}
*/
