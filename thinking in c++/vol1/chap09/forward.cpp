/*************************************************************************
	> File Name: forward.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sun, Jul 28, 2013  5:28:33 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class forward {
	public:
		forward() : i(0) { }
		
		int f() const 
		{
			return g() + 1;
		}
			
		int g() const
		{	
			return i;
		}

	private:
		int i;
};

int 
main(void)
{
	forward f;
	f.f();
	return 0;
}



