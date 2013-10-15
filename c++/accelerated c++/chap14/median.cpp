#include "median.h"
#include <vector>
#include <algorithm>

using namespace std;

double median(std::vector<double> s)
{
	sort(s.begin(), s.end());
	vector<double>::size_type sz = s.size() / 2;

	return s.size() % 2 == 1 ? s[sz] : (s[sz] + s[sz - 1]) / 2;
}