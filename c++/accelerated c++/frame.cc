/*************************************************************************
	> File Name: frame.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月22日 星期二 11时08分39秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string::size_type width(const vector<string>& s)
{
	string::size_type	maxlen = 0;
	for (vector<string>::const_iterator i = s.begin(); i != s.end(); i ++)
		maxlen = max(maxlen, (*i).size());
	return maxlen;
}

vector<string> frame(const vector<string>& s)
{
	vector<string>	ret;
	string::size_type	len = width(s);
	ret.push_back(string(len + 4, '*'));
	for (vector<string>::const_iterator i = s.begin(); i != s.end(); i ++) {
		ret.push_back("* " + (*i) + string(len - (*i).size(), ' ') + " *");
	}
	ret.push_back(string(len + 4, '*'));
	return ret;
}

vector<string> vcat(const vector<string>& a, const vector<string>& b)
{
	vector<string> ret = a;
	ret.insert(ret.end(), b.begin(), b.end());
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	string::size_type	len = width(left) + 1;
	vector<string>::size_type	i = 0, j = 0; 
	while(i != left.size() || j != right.size()) {
		string s;
		if (i != left.size())
			s = left[i++];
		s += string(len - s.size(), ' ');
		if (j != right.size())
			s += right[j ++];
		ret.push_back(s);
	}
	return ret;
}

vector<string> split(const string s)
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

void show(const vector<string>& s)
{
	for (vector<string>::const_iterator i = s.begin(); i != s.end(); i ++)
		cout << *i << endl;
}

int main(void)
{
	string	s;
	getline(cin, s);

	vector<string> vc = split(s);
	vector<string> f = frame(vc);
	show(f);
	show(vcat(f, vc));
	show(hcat(vc, f));
	return 0;
}


