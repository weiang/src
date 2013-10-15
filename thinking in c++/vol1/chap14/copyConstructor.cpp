/*************************************************************************
	> File Name: copyConstructor.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013  8:53:58 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class p {
	public:
		p(int ii = 0) : i(ii) { cout << "p(int ii = 0) " << endl; }	// Default constructor
		p(const p& pp) : i(pp.i) { cout << "p(const p&) " << endl; }	// Copy constructor
		
	private:
		int i;
};

class m {
	public:
		m(int ii = 0) : i(ii) { cout << "m(int ii = 0) " << endl; }	// Default constructor
		m(const m& mm) : i(mm.i) { cout << "m(const m&) " << endl; }	// Copy constructor

	private:
		int i;
};

class c : public p {
	public:
		c(int ii = 0) : p(), mem(), i(ii) { cout << "c(int ii = 0)" << endl; } // Default constructor
		c(const c& cc) : p(cc), mem(cc.mem), i(cc.i) { cout << "c(const c&) " << endl; } // Copy constructor

	private:
		int i;
		m mem;	// composition class 
};


int 
main(void)
{
	c a;
	c a1(a);

	return 0;
}
