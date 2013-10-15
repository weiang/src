/*************************************************************************
	> File Name: iterator.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Mon, Aug 12, 2013 11:10:36 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

int main()
{
	vector<int> e;
	copy(istream_iterator<int>(cin), 
			istream_iterator<int>(), 
			back_inserter(e));
	vector<int>::iterator first = find(e.begin(), e.end(), 100);
	assert(first != e.end());
	vector<int>::iterator last = find(e.begin(), e.end(), 10);
	assert(last != e.end());
	*last = 11;
	assert(first < last);
	copy(first, last, ostream_iterator<int>(cout, "\n"));
	e.insert(e.end() - 1, 12);
	copy(first, last, ostream_iterator<int>(cout, "\n"));

	return 0;
}
			

