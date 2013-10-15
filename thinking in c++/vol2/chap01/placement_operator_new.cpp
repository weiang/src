/*************************************************************************
	> File Name: placement_operator_new.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 02时03分01秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstddef>

using namespace std;

class X {
	public:
		X(int ii) : i(ii)
		{
			cout << "This = " << this << endl;
		}

		~X() 
		{
			cout << "X::~X(): " << this << endl;
		}

		void* operator new(size_t, void *loc)
		{
			return loc;
		}

	private:
		int i;
};

int main()
{
	int l[10];
	cout << "l = " << l << endl;
	X *xp = new(l) X(47);
	xp->X::~X();
	
	return 0;
}
