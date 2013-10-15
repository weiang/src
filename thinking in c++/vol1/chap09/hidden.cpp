/*************************************************************************
	> File Name: hidden.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  5:34:48 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class member {
		int i, j, k;
	public:
		//member(int x = 0) : i(x), j(x), k(x) { cout << "member" << endl; }
		member(int x = 0);
		//~member() {	cout << "~member()" << endl; }
		~member();	
};

class withmember {
		member q, r, s;
		int i;
	public:
		//withmember(int ii) : i(ii) { cout << "withmember" << endl; }
		//~withmember() { cout << "~withmember()" << endl; }
		withmember(int);
		~withmember();
};

inline
member::member(int x /* = 0 */) : i(x), j(x), k(x)
{
	cout << "member" << endl;
}

inline
member::~member()
{
	cout << "~member" << endl;
}

inline
withmember::withmember(int ii) : i(ii)
{
	cout << "withmember" << endl;
}

inline
withmember::~withmember()
{
	cout << "~withmember" << endl;
}

	
int 
main(void)
{
	withmember a(2);
	return 0;
}


