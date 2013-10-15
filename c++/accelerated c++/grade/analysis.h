#ifndef _ANALYSE_H_
#define _ANALYSE_H_

#include "student_info.h"
#include <iostream>
#include <vector>
#include "extract.h"

void write_analysis(std::ostream&, const std::string&, 
					double analysis(const module&), 
					const module&, 
					const module&);

double median_analysis(const module&);
double average_analysis(const module&);
double optimistic_median_analysis(const module&);

#endif
