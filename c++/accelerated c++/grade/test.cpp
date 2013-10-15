/*************************************************************************
	> File Name: test.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 12时21分30秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "student_info.h"
#include "analysis.h"
#include "grade.h"
#include "median.h"


using namespace std;

int main(void)
{
	module did, didnt;

	student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else 
			didnt.push_back(student);
	}

	if (did.empty()) {
		cout << "No student did all homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of the homework turned in",
					optimistic_median_analysis, did, didnt);

	return 0;
}
