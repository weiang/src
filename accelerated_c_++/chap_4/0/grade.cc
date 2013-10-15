#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <stdexcept>

using namespace std;

double
grade(double midterm, double final, double homework)
{
	return W_MID * midterm + W_FIN * final + W_HOM * homework;
}

double
grade(double midterm, double final, const vector<double> &hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework!");
	return grade(midterm, final, median(hw));
}

double 
grade(const Student_info &student)
{
	return grade(student.midterm, student.final, student.homework);
}

