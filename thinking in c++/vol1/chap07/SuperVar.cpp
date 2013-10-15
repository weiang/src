/*************************************************************************
	> File Name: SuperVar.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013 12:50:03 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SuperVar {
	public:
		SuperVar(char);
		SuperVar(int);
		SuperVar(float);
		void print();

	private:
		enum {
			character,
			integer, 
			floating_point
		} vartype;
	
		union {		// Anonymous union
			char c;
			int i;
			float f;
		};
};
	
SuperVar::SuperVar(char ch)
{
	vartype = character;
	c = ch;
}

SuperVar::SuperVar(int ii)
{
	vartype = integer;
	i = ii;
}

SuperVar::SuperVar(float ff)
{
	vartype = floating_point;
	f = ff;
}

void 
SuperVar::print()
{
	switch (vartype) {
		case character:
			cout << "character: " << c << endl;
			break;
		case integer:
			cout << "integer: " << i << endl;
			break;
		case floating_point:
			cout << "float: " << f << endl;
			break;
	}
}

int 
main(void)
{
	SuperVar A('c'), B(12), C(1.44f);
	A.print();
	B.print();
	C.print();
	return 0;
}


