/*************************************************************************
	> File Name: xref.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 20时46分49秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"
#include "url.h"
#include <algorithm>

using namespace std;

map<string, vector<int> >
xref(istream& in, vector<string> fun(const string&) = split)
{
	string	s;

	map<string, vector<int> > ret;

	int	line_num	= 0;
	while (getline(in, s)) {
		line_num ++;
		vector<string> r = fun(s);

		for (vector<string>::const_iterator i = r.begin(); i != r.end(); i ++) {
			if (find(ret[*i].begin(), ret[*i].end(), line_num) == ret[*i].end())
				ret[*i].push_back(line_num);
		}
	}
	return ret;
}

int main()
{
	map<string, vector<int> > ret = xref(cin);

	for (map<string, vector<int> >::const_iterator i = ret.begin(); i != ret.end(); i ++) {
		cout << i -> first << " occurs on line: ";

		vector<int>::const_iterator	j = (i -> second).begin();
		cout << *j;
		j ++;
		int count = 1;
		while (j != (i -> second).end()) {
				if (count == 0)
					cout <<  *j;
				else 
					cout << ", " << *j;
				j ++;
				count ++;
				if (count == 10) {
					cout << endl;
					count = 0;
				}
		}
		cout << endl;
	}
	return 0;
}


