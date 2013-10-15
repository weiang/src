/*************************************************************************
	> File Name: staticMemberFunctions.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Mon, Jul 29, 2013  4:15:43 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class X {
	public:
		X(int ii = 0) : i(ii) 
		{
			j = i;
		}

		int val() const { return i; }

		static int incr() 
		{
//			i ++;
			return ++j;
		}

		static int f() 
		{
//			val();
			return incr();
		}

	private:
		int i;
		static int j;
};

int X::j = 0;

int 
main(void)
{
	X x;
	X* xp = &x;
	x.f();
	xp -> f();
	X::f();
	return 0;
}


