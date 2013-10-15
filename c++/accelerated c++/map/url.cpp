/*************************************************************************
	> File Name: url.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月22日 星期二 23时04分47秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "url.h"

using namespace std;

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	string::const_iterator i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
			if (i != b && i + sep.size() != e) {
				string::const_iterator beg;
				beg = i;
				while (beg != b && isalpha(beg[-1]))
					-- beg;
				if (beg != i && !not_url_char(i[sep.size()])) 
					return beg;
			}
			i += sep.size();
		}
		return e;
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) ||
			find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

vector<string>
find_urls(const string& s)
{
	vector<string>	ret;

	string::const_iterator b, e;
	b = s.begin();
	e = s.end();

	while(b != e) {
		b = url_beg(b, e);
		if (b != e) {
			string::const_iterator after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}


