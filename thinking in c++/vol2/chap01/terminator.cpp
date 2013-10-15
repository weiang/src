/*************************************************************************
	> File Name: terminator.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Aug 01, 2013  4:11:55 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <exception>

using namespace std;

void terminator() 
{
	cout << "I'll be back!" << endl;
}

void (*old_terminator)() = set_terminate(terminator);

class Botch {
	public:
		class Fruit {};
		
		void f() {
			cout << "Botch::f() " << endl;
			throw Fruit();
		}
		
		~Botch() 
		{
			throw 'c';
		}
};

int 
main()
{
	try {
		Botch b;
		b.f();
	} catch(...) {
		cout << "Inside catch(...) " << endl;
	}
	return 0;
}

			
