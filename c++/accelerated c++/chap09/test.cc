/*************************************************************************
	> File Name: test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月25日 星期五 20时01分55秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "student_info.h"
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>

using namespace std;

void report(const vector<student_info>& s, int n)
{
	for (vector<student_info>::const_iterator it = s.begin();
			it != s.end(); it ++) {
		cout << it -> name() << string(n - (it -> name()).size() + 1, ' ');
		try {
			streamsize	pre = cout.precision();
			cout << setprecision(3) << it -> grade()
				 << setprecision(pre) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
			return;
		}
	}
}

int main()
{
	string::size_type	maxlen = 0;

	vector<student_info>	students;
	student_info	record;
	while (record.read(cin)) {
		students.push_back(record);
		maxlen = max(maxlen, record.name().size());
	}

	sort(students.begin(), students.end(), compare);
	report(students, maxlen);
	return 0;
}

