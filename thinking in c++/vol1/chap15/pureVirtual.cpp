/*************************************************************************
	> File Name: pureVirtual.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013  9:53:38 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class pet {
	public:
		virtual void eat() const = 0;
		virtual void speak() const = 0;
		virtual void sleep() const = 0;
};

void 
pet::eat() const 
{
	cout << "pet::eat() " << endl;
}

void 
pet::speak() const
{
	cout << "pet::speak() " << endl; 
}

void 
pet::sleep() const
{
	cout << "pet::sleep() " << endl;
}


class dog : public pet {
	public:
		void eat() const 
		{
			pet::eat();
		}

		void speak() const
		{
			pet::speak();
		}

		void sleep() const
		{
			pet::sleep();
		}

};

int 
main(void)
{
//	pet p;
	dog d;
	d.eat();
	d.speak();
	d.sleep();
	return 0;
}
