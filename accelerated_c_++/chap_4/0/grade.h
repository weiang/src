#ifndef _GRADE_H_
#define _GRADE_H_

#include <iostream>
#include <string>
#include <vector>

#define W_MID	0.4
#define W_FIN	0.4
#define W_HOM	0.2

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);

#endif 


