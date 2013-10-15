/*************************************************************************
	> File Name: student_info.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月25日 星期五 19时16分24秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "student_info.h"
#include "grade.h"

using namespace std;

student_info::student_info() : midterm(0), final(0) {	}
student_info::student_info(istream& in)
{
	read(in);
}

void read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
}

istream&
student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double
student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool compare(const student_info& a, const student_info& b)
{
	return a.name() < b.name();
}
