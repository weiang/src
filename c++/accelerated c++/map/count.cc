/*************************************************************************
	> File Name: count.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 20时08分36秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	string	s;
	map<string, int> counters;

	while (cin >> s)
		++ counters[s];

	map<int, vector<string> > groups;
	for (map<string, int>::const_iterator i = counters.begin(); i != counters.end(); i ++)
		groups[i -> second].push_back(i -> first);
	for (map<int, vector<string> >::const_iterator it = groups.begin(); it != groups.end(); it ++) {
		cout << "Occurence " << it -> first << ": ";
		vector<string>::const_iterator j = it -> second.begin();
		cout << *j;
		j ++;
		while (j != it -> second.end()) {
			cout << ", " << *j;
			j ++;
		}
		cout << endl;
	}

	return 0;
}
