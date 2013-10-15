/*************************************************************************
	> File Name: car.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013 10:44:40 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class engine {
	public:
		void start() const { }
		void rev() const { }
		void stop() const { }
};

class wheel {
	public:
		void inflate(int psi) const { }
};

class window {
	public:
		void rollup() const { }
		void rolldown() const { }
};

class door {
	public:
		window w;
		void open() const { }
		void close() const { }
};

class vehicle {
	public:
		vehicle(int ii) : i(ii) { }

	private:
		int i;
};

class car : public vehicle {
	public:
		car(int i = 0) : vehicle(i) { }
		car(const car& c) : vehicle(c), e(c.e), we(c.we), left(c.left), right(c.right) { }

	private:
		engine e;
		wheel we;
		door left, right;
};

int 
main(void)
{
	car c;
	car c1(2);
	return 0;
}

