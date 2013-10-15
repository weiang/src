#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double 
median(vector<double> hw)
{
	sort(hw.begin(), hw.end());
	vector<double>::size_type sz = hw.size() / 2;
	if (hw.size() == 0) 
		throw domain_error("Student has done no homework");

	return hw.size() % 2 == 0 ? (hw[sz] + hw[sz + 1]) / 2 : hw[sz + 1];
}


