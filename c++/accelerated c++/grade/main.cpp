#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include "grade.h"
#include "student_info.h"
#include "extract.h"
#include <fstream>

using namespace std;

void show_result(const student_info&, int);

int main(void)
{
	module	students;
	student_info	record;
	string::size_type	maxlen = 0;

	while(read(cin, record)) {
		students.push_back(record);
		maxlen = max(maxlen, record.name.size());
	}
	
//	module	fail = extract_fail(students);
//	fail.sort(compare);
//	students.sort(compare);
	// sort(students.begin(), students.end(), compare);
//	for (module::const_iterator i = students.begin(); i != students.end(); i ++) 
//		show_result(*i, maxlen);
//	for (module::const_iterator i = fail.begin(); i != fail.end(); i ++)
//		show_result(*i, maxlen);
	map<string, int> r = range(students);
	for (map<string, int>::const_iterator it = r.begin(); it != r.end(); it ++) {
		cout << it -> first << "\t" << it -> second;
		cout << endl;
	}

	return 0;
}

void show_result(const student_info& s, int len)
{
	cout << (s.name) << string(len + 1 - (s.name).size(), ' ');
	try {
		streamsize	pre	= cout.precision();
		double final_grade = grade(s);
		cout << setprecision(3) << final_grade << setprecision(pre) << endl;
	} catch (domain_error e) {
		cout << e.what();
	}
}
