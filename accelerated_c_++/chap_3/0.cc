/*************************************************************************
	> File Name: 0.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 19时55分40秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <algorithm>
#include <iomanip>

using namespace std;

#define W_MID	0.4
#define W_FIN	0.4
#define W_HOM	0.2

int 
main(void)
{
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	cout << "Please enter your midterm , final exam grade: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Please enter your homework grades " 
			"followed by end-of-file: ";
	vector<double> homework;
	double tmp;
	while (cin >> tmp) {
		homework.push_back(tmp);
	}

	sort(homework.begin(), homework.end());
	vector<double>::size_type sz = homework.size();
	if (sz == 0) {
		cout << endl << "You must enter your homework grades! "
						"Please try again!" << endl;
		return 1;
	}
	double homegrade = sz % 2 == 0 ? (homework[sz % 2] + homework[sz % 2 + 1]) / 2 : homework[sz % 2 + 1];
	
	streamsize prec = cout.precision();
	double finalgrade = W_MID * midterm + W_FIN * final + W_HOM * homegrade;
	cout << "Your final grade is: " << setprecision(3) << finalgrade << setprecision(prec) << endl;

	return 0;
}
