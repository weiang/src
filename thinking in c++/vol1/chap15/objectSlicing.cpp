/*************************************************************************
	> File Name: objectSlicing.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 31, 2013  5:15:28 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class pet {
		string pname;
	public:
		pet(const string& name) : pname(name) { }
		virtual string name() const { return pname; }
};

int 
main(void)
{
	pet p("wangwang");
	return 0;
}
		
