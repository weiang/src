/*************************************************************************
	> File Name: init_except.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 02时14分06秒
    > Describition: 
 ************************************************************************/
#include <iostream>

using namespace std;

class Base {
	public:
		class BaseExcept { };
		Base(int ii) : i(ii) { throw BaseExcept(); }

	private:
		int i;
};

class Derived : public Base {
	public:
		class DerivedExcept {
			public:
				DerivedExcept(const char *msg) : msg(msg) {} 
				const char *what() const { return msg; }

			private:
				const char *msg;
		};

		Derived(int j) try : Base(j) 
		{
			cout << "This won't be printed" <<endl;
		} catch (BaseExcept) {
			throw DerivedExcept("Base subobject threw");
		}
};

int  main()
{
	try {
		Derived d(3);
	} catch(Derived::DerivedExcept& d) {
		cout << d.what() << endl;
	}
}
