/*************************************************************************
	> File Name: 6_1.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  4:16:12 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Simple {
	public:
		Simple(int a);
		~Simple();
	private:
		int i;
};

Simple::Simple(int a)
{
	i = a;
	cout << "In construct: i = " << i << endl;
}

Simple::~Simple()
{
	cout << "In desconstruct: i = " << i << endl;
}


int 
main(void)
{
	cout << "Before Defination" << endl;
	{
		cout << "After left (" << endl;
		Simple s(2);
		goto exit;
		cout << "Before right )" << endl;
	}
exit:
	return 0;
}
