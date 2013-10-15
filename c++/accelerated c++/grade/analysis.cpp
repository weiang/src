#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "student_info.h"
#include "grade.h"
#include "median.h"
#include "analysis.h"
#include <stdexcept>

using namespace std;

double grade_aux(const student_info& s);

void write_analysis(ostream& out, const string s,
					double analysis(const module&),
					const module& did,
					const module& didnt)
{
	out << s << ": median(did) = " << analysis(did)
		<< ", median(didnt) = " << analysis(didnt) << endl;
}

double median_analysis(const module& s)
{
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double grade_aux(const student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0.0);
	}
}


