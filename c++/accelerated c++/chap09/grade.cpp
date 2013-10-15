#include "grade.h"
#include "median.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace	std;

double grade(double	middle, double	final, double average)
{
	return middle * 0.2 + final * 0.4 + average * 0.4;
}

double grade(double middle, double final, const vector<double>& v)
{
	if (v.size() == 0)
		throw domain_error("student has done no homework!");
	return grade(middle, final, median(v));
}
/*
double grade(const student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
*/
/*
istream& read_hw(istream& in, vector<double>& homework)
{
	if (in) {
		homework.clear();
		double	x;
		while(in >> x)
			homework.push_back(x);
		in.clear();
	}
	return in;
}

istream& read(istream& in, student_info& s)
{
	in >> s.name;
//	cout << "Please enter your midterm grade: ";
	in >> s.midterm;
//	cout << "Please enter your final grade: ";
	in >> s.final;
//	cout << "Please enter your homework grades(end with eof): " << endl;
	read_hw(in, s.homework);
	return in;
}

bool compare(const student_info& a, const student_info& b)
{
	return a.name < b.name;
}

double grade_aux(const student_info& s)
{
	return grade(s);
}

map<string, int>
range(const module& s)
{
	map<string, int> ret;
	vector<double>	grades;

	transform(s.begin(), s.end(), back_inserter(grades), grade_aux);

	for (vector<double>::const_iterator it = grades.begin(); it != grades.end(); it ++) {
		if (*it >= 90)
			ret["A"] ++;
		else if (*it >= 80)
			ret["B"] ++;
		else if (*it >= 70)
			ret["C"] ++;
		else if (*it >= 60)
			ret["D"] ++;
		else 
			ret["F"] ++;
	}
	return ret;
}
*/
