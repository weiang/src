/*************************************************************************
	> File Name: y.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  4:11:54 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Y {
	public:
		float f;
		int i;
		Y(int a);
		Y();
};

Y::Y(int a)
{
	i = a;
	f = 0.0;
}

Y::Y()
{
}

int 
main(void)
{
	Y y;
	return 0;
}
