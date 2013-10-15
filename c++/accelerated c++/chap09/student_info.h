#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <vector>
#include <iostream>

class student_info {
	public:	
		student_info();
		student_info(std::istream& in);
		std::string name() const	{ return n;	}
		bool valid() const	{	return !homework.empty();	}
		std::istream& read(std::istream&);
		double grade() const;

	private:
		std::string n;
		double midterm, final;
		std::vector<double> homework;
};

bool compare(const student_info&, const student_info&);

#endif
