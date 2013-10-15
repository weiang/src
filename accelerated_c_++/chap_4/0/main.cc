/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月27日 星期四 11时37分55秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>

using namespace std;

int 
main(void)
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	while (cin >> record.name) {
		read(cin, record);
		students.push_back(record);
		maxlen = max(maxlen, record.name.size());
	}
	
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); i ++) {
		try {
			streamsize prec = cout.precision();
			double final = grade(students[i]);
			cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ')
				 << setprecision(3) << final << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
			return 1;
		}
	}
	return 0;
}
	
