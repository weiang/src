/*************************************************************************
	> File Name: bad_exception.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 10时44分43秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <exception>
#include <cstdlib>

using namespace std;

class A {};
class B {};

// Terminate() handler
void my_thandler() 
{
	cout << "Terminate called " << endl;
	exit(0);
}

// Unexpected() handlers 
void my_uhandler1()
{
	throw A();
}

void my_uhandler2()
{
	throw;
}

void t()
{
	throw B();
}

void f() throw(A)
{
	t();
}

void g() throw(A, bad_exception)
{
	t();
}

int main()
{
	set_terminate(my_thandler);
	set_unexpected(my_uhandler1);
	try {
		f();
	} catch (A&) {
		cout << "Catch A from f() " << endl;
	}

	set_unexpected(my_uhandler2);
	try {
		g();
	} catch (bad_exception&) {
		cout << "Catch bad_exception from g()" << endl;
	}

	try {
		f();
	} catch (...) {
		cout << "This will never print" << endl;
	}

	return 0;
}

