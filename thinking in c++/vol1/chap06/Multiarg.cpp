/*************************************************************************
	> File Name: Multiarg.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  4:03:00 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Z {
	public:
		Z(int i, int j);
		void print();
	private:
		int i, j;
};

Z::Z(int ii, int jj)
{
	i = ii;
	j = jj;
}

void
Z::print()
{
	cout << "i = " << i
		<< " j = " << j 
		<< endl;
}

int 
main(void)
{
	Z zz[] = {{1, 2}, Z(3, 4), Z(5, 6)};

	for (int i = 0; i < sizeof(zz) / sizeof*zz; i ++)
		zz[i].print();
	return 0;
}
