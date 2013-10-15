#include <algorithm>
#ifndef __GNUC__
#include <ios>
#endif
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "handle.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif
/*
bool compare_Core_handles(const handle<core>& lhs, const handle<core>& rhs) {
	return compare(*lhs, *rhs);
}
*/
int main()
{
	vector< handle<core> > students;       // changed type
	handle<core> record;                   // changed type
	char ch;
	string::size_type maxlen = 0;

	// read and store the data
	while (cin >> ch) {
		if (ch == 'U')
			record = new core;      // allocate a `Core' object
		else
			record = new grad;      // allocate a `Grad' object

		record->read(cin);  //  `Handle<T>::->', then `virtual' call to `read'
		maxlen = max(maxlen, record->name().size()); // `Handle<T>::->'
		students.push_back(record);
	}

	// `compare' must be rewritten to work on `const handle<core>&'
	sort(students.begin(), students.end(), handle<core>::compare_handle);

	// write the names and grades
#ifdef _MSC_VER
	for (std::vector< handle<core> >::size_type i = 0;
#else
	for (vector< handle<core> >::size_type i = 0;
#endif
	     i != students.size(); ++i) {
		// `students[i]' is a `Handle', which we dereference to call the functions
		cout << students[i]->name()
		     << string(maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
		// no `delete' statement
	}
	return 0;
}

