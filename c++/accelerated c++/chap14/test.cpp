#include "student_info.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "analysis.h"
#include <ios>
#include <stdexcept>
#include <iomanip>
#include <unistd.h>
#include "handle.h"

using namespace std;

/*
 * First version: Using core and grad class 
 */
/*
int main()
{
	vector<core*> students;
	core* record;
	string::size_type maxlen = 0;
	char c;

	while (cin >> c) {
		if (c == 'U')
			record = new core;
		else 
			record = new grad;
		record -> read(cin);
		maxlen = max(maxlen, record -> name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_name_ptr);

	for (vector<core*>::const_iterator it = students.begin(); it != students.end(); it ++) {
		cout << (*it) -> name() << string(maxlen + 1 - (*it) -> name().size(), ' ');
		try {
			double final_grade = (*it) -> grade();
			streamsize pre = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(pre) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
			return 1;
		}
		delete *it;
	}
	return 0;
}
*/

/*
 * Second version: Using student_info class
 */
/*
int main(void)
{
	vector<student_info> students;
	student_info	record;
	string::size_type maxlen = 0;

	while (record.read(cin)) {
		students.push_back(record);
		maxlen = max(maxlen, record.name().size());
	}
	sort(students.begin(), students.end(), student_info::compare);

	for (vector<student_info>::const_iterator it = students.begin(); 
			it != students.end(); it ++) {
		cout << it -> name() 
			 << string(maxlen + 1 - it -> name().size(), ' ') << endl;
		try {
			double final_grade = it -> grade();
			streamsize pre = cout.precision();
			cout << setprecision(3) << final_grade 
				 << setprecision(pre) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
			return 1;
		}
	}
	return 0;
}
*/

/* 
 * Exercise of chapter 13
 */
/*
int main(void)
{
	core* p1 = new core(cin);
	core* p2 = new grad(cin);
	core s1(cin);
	grad s2(cin);

	p1 -> grade();
	cout << "P(d): from core::grade()" << endl;
	p1-> name();
	cout << "P(d): from core::name()" << endl;
	
	p2 -> grade();
	cout << "P(d): from grad::grade()" << endl;
	p2 -> name();
	cout << "P(d): from core::name()" << endl;

	s1.grade();
	cout << "P(s): from core::grade() " << endl;
	s1.name();
	cout << "P(s): from core::name()" << endl;

	s2.name();
	cout << "P(s): from core::name()" << endl;
	s2.grade();
	cout << "P(s): from grad::grade()" << endl;

	return 0;
}
*/

/*
 * Third version: Using class handle
 */
int main(void)
{

	vector<handle<core> > students;
	handle<core> record;
	string::size_type maxlen = 0;

	char ch;
	
	while (cin >> ch) {
		if (ch == 'U')
			record = new core;
		else 
			record = new grad;
		(record.operator->()) -> read(cin);
		students.push_back(record);
		maxlen = max(maxlen, (*record).name().size());
	}

	sort(students.begin(), students.end(), handle<core>::compare_handle);

	for (vector<handle<core> >::const_iterator it = students.begin();
			it != students.end(); it ++) {
		cout << (*it) -> name()
			 << string(maxlen + 1 - (*it) -> name().size(), ' ') << endl;
		streamsize pre = cout.precision();
		try {
			double final_grade = (it -> operator->()) -> grade();
			cout << setprecision(3) << final_grade 
				 << setprecision(pre) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
			return 1;
		}
	}
	return 0;
}
