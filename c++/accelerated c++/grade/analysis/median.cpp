#include "median.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double	median(vector<double> v)
{	
	vector<double>::size_type	size = v.size();
	if (size == 0) {
		throw	domain_error("Median of an empty vector!");
		return 1;
	}
	sort(v.begin(), v.end());
	vector<double>::size_type	mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}