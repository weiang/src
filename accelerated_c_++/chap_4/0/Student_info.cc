#include <vector>
#include <string>
#include <iostream>
#include "Student_info.h"

using namespace std;

istream &
read_hw(istream &in, vector<double> &hw)
{
	if (in) {
		hw.clear();
		double tmp;
		while (in >> tmp) {
			hw.push_back(tmp);
		}
		in.clear();
	}
	return in;
}

istream &
read(istream &in, Student_info &student)
{
	if (in) {
		/* Get student's middle term and final exam grade */
		in >> student.midterm >> student.final;

		/* Get studnet's homework grade */
		read_hw(in, student.homework);
	}
	return in;
}

bool 
compare(const Student_info &student1, const Student_info &student2)
{
	return student1.name < student2.name;
}

