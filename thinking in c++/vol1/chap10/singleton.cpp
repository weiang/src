/*************************************************************************
	> File Name: singleton.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Mon, Jul 29, 2013  4:29:31 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Egg {
		static Egg e;
		int i;
		Egg(int ii) : i(ii) { }
		Egg(const Egg &);
		friend void fun();

	public:
		static Egg *instance() { return &e; }
		int val() const { return i; }
};

Egg Egg::e(47);

Egg::Egg(const Egg& a)
{
	i = a.i;
}

void fun()
{
	Egg e(*Egg::instance());
	cout << "In fun(): " << e.val() << endl;
}

int 
main(void)
{
	cout << Egg::instance() -> val() << endl;
//	Egg e(*Egg::instance());
	fun();
	return 0;
}




