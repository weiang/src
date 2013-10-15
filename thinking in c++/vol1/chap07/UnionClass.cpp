/*************************************************************************
	> File Name: UnionClass.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013 12:35:21 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

union U {
	public:
		U(int);
		U(float);
		~U();
		int read_int();
		float read_float();

	private:
		int i;
		float f;
};

U::U(int ii)
{
	i = ii;
}

U::U(float ff)
{
	f = ff;
}

U::~U()
{
	cout << "U::U()" << endl;
}

int 
U::read_int()
{
	return i;
}


float
U::read_float()
{
	return f;
}

int
main(void)
{
	U x(12), y(1.9f);
	cout << x.read_int() << endl;
	cout << x.read_float() << endl;
	cout << y.read_int() << endl;
	cout << y.read_float() << endl;
	return 0;
}


