#include "grade.h"
#include <vector>
#include <istream>

using namespace std;

double grade(double midterm, double final, double homework)
{
	return 0.4 * final + 0.4 * homework + 0.2 * midterm;
}

istream& read_hw(istream& in, vector<double>& s)
{
	s.clear();
	double x;
	while (in >> x) {
		s.push_back(x);
	}
	in.clear();
	return in;
}


