/*************************************************************************
	> File Name: 15_1.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013 11:58:05 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class shape {
	public:
		shape() { cout << "shape::constructor" << endl; }
		virtual void draw() const = 0;
};

void
shape::draw() const 
{
	cout << "shape::draw() " << endl;
}

class circle : public shape {
	public:
		void draw() const;
};

void
circle::draw() const
{
	cout << "circle::draw() " << endl;
}

class square : public shape {
	public:
		void draw() const;
};

void 
square::draw() const
{
	cout << "square::draw() " << endl;
}

class triangle : public shape {
	public: 
		void draw() const;
};

void
triangle::draw() const
{
	cout << "triangle::draw() " << endl;
}


void 
fun(const shape& s)
{
	s.draw();
}

int 
main(void)
{
	circle c;
	square s;
	triangle t;

	shape *ps[] = {&c, &s, &t};

	for (int i = 0; i < sizeof(ps) / sizeof *ps; i ++) {
		ps[i] -> draw();
		fun(*ps[i]);
	}
	
	return 0;
}


