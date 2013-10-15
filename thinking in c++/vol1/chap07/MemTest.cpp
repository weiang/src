/*************************************************************************
	> File Name: MemTest.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  2:02:36 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstring>
#include "Mem.h"

using namespace std;

class MyString {
	public:
		MyString();
		MyString(char *);
		~MyString();
		void concat(char *str);
		void print(ostream& os);

	private:
		Mem *buf;
};

MyString::MyString()
{
	buf = NULL;
}

MyString::MyString(char *str)
{
	buf = new Mem(strlen(str) + 1);
	strcpy((char *)buf -> pointer(), str);
}

MyString::~MyString()
{
	delete buf;
}

void 
MyString::concat(char *str)
{
	if (!buf) 
		buf = new Mem;
	strcat((char *)buf -> pointer(strlen(str) + buf -> msize() + 1), str);
}

void
MyString::print(ostream& os)
{
	if (!buf)
		return;
	os << buf -> pointer() << endl;
}

int 
main(void)
{
	MyString s("My test String");
	s.print(cout);
	s.concat(" Some additional stuff");
	s.print(cout);
	MyString s2;
	s2.concat("Using default constructor");
	s2.print(cout);
	return 0;
}


