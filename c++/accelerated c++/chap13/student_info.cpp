#include <algorithm>
#include <vector>
#include <string>
#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * For core class implementation
 */
core::core() : midterm(0), final(0) 
{
	cout << "Default constructor: core::core()" << endl;
}

core::core(istream& in) 
{ 
	cout << "Construtor: core::core(istream& in)" << endl;
	read(in); 
}

string core::name() const
{ 
	cout << "core::name() member function" << endl;
	return n; 
}

double core::grade() const
{ 
	cout << "core::grade() member function" << endl;
	return ::grade(midterm, final, median(homework)); 
}

istream& core::read_common(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

istream& core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

bool core::valid() const
{
	return !n.empty() && homework.size();
}

/* 
 * For grad class implementation
 */
grad::grad() : thesis(0) 
{ 
	cout << "Default constructor: grad::grad()" << endl;
}

grad::grad(istream& in) 
{ 
	cout << "Constructor: grad::grad(istream& in) " << endl;
	read(in); 
}

istream& grad::read(istream& in) 
{
	core::read_common(in);
	in >> thesis;
	read_hw(in, core::homework);
	return in;
}

double grad::grade() const
{
	cout << "grad::grade() member function" << endl;
	return min(::grade(core::midterm, core::final, median(core::homework)), thesis);
}
/*
 * For student_info class implementation
 */
istream& student_info::read(istream& in)
{
	delete cp;
	char ch;
	in >> ch;
	if (ch == 'U')
		cp = new core(in);
	else 
		cp = new grad(in);
	return in;
}

student_info::student_info(const student_info& s) : cp(0)
{
	if (s.cp) 
		cp = s.cp ->  clone();
}

student_info& student_info::operator=(const student_info& s)
{
	if (this != &s) {
		delete cp;
		if (s.cp)
			cp = s.cp -> clone();
		else 
			cp = 0;
	}
	return *this;
}

