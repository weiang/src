/*************************************************************************
	> File Name: 14_27.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013 11:07:52 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class subject {
	public:
		virtual void f() = 0; 
		virtual void g() = 0;
		virtual void h() = 0;
};

class proxy : subject {
	public:
		proxy(subject * sub) : s(sub) { }
		void f() { s -> f(); }
		void g() { s -> g(); }
		void h() { s -> h(); }
		void setSubject(subject *sub) { s = sub; }

	private:
		subject *s;
};

class i1 : public subject {
	public:
		void f() { cout << "i1::f() " << endl; }
		void g() { cout << "i1::g() " << endl; }
		void h() { cout << "i1::h() " << endl; }
};

class i2 : public subject {
	public:
		void f() { cout << "i2::f() " << endl; }
		void g() { cout << "i2::g() " << endl; }
		void h() { cout << "i2::h() " << endl; }
};
		
int 
main(void)
{	
	i1 a;
	proxy p(&a);
	p.f();
	p.g();
	p.h();

	i2 b;
	p.setSubject(&b);
	p.f();
	p.g();
	p.h();
	return 0;
}

