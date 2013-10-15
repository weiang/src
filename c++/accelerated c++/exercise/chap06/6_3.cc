/*************************************************************************
	> File Name: 6_3.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 19时00分39秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int>	u(10, 100);
	for (vector<int>::size_type i = 0; i != u.size(); i ++)
		cout << u[i] << endl;
	vector<int> v;
	copy(u.begin(), u.end(), v.begin());

	for (vector<int>::const_iterator i = v.begin(); i != v.end(); i ++)
		cout << *i << endl;
	return 0;
}
