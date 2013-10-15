#ifndef	_GRADE_H_
#define	_GRADE_H_

#include "student_info.h"
#include <vector>
#include <map>
#include "extract.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const student_info&);

std::map<std::string, int>
range(const module&);

#endif


