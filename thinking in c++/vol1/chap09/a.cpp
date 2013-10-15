/*************************************************************************
	> File Name: a.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  5:15:12 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
	public:
		void print()
		{
			cout << "Hello, world!" << endl;
		}

	private:
		int i;
};


int
main(void)
{
	A a;
	cout << sizeof a << endl;
	return 0;
}


