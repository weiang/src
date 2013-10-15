#ifndef	_GRADE_H_
#define	_GRADE_H_

#include "student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const student_info&);

#endif


