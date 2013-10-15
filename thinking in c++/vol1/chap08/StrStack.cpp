/*************************************************************************
	> File Name: StrStack.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  2:05:00 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class StrStack {
	public:
		StrStack();
		void push(const string *);
		const string *pop();

	private:
		static const int size = 100;
		const string *stack[size];
		int index;
};


StrStack::StrStack() : index(0) 
{ 
	memset(stack, 0, sizeof(stack));
}


void
StrStack::push(const string *pstr)
{
	if (index < size) 
		stack[index ++] = pstr;
	else 
		cout << "Stack overflow!" << endl;
}

const string *
StrStack::pop()
{
	if (index > 0) {
		const string *rv = stack[-- index];
		stack[index] = 0;
		return rv;
	}
	else {
		cout << "Stack empty!" << endl;
		return NULL;
	}
}

string iceCream[] = {
	"pralines & cream",
	"fudge ripple", 
	"jamocha almond fudge", 
	"wild mountain blackberry",
	"raspberry sorbet"
};

const int isz = sizeof iceCream / sizeof *iceCream;

int 
main(void)
{
	StrStack ss;
	for (int i = 0; i < isz; i ++)
		ss.push(&iceCream[i]);
	
	string *cp;
	while ((cp = ss.pop()) != 0)
		cout << *cp << endl;
	return 0;
}


