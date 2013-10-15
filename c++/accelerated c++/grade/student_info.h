#ifndef	_STUDENT_INFO_H_
#define	_STUDENT_INFO_H_

#include <string>
#include <iostream>
#include <vector>

struct student_info {
	std::string	name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const student_info&, const student_info&);
std::istream& read(std::istream&, student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
