/*************************************************************************
	> File Name: UseHandle.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Jul 26, 2013  4:38:23 PM
    > Describition: 
 ************************************************************************/

#include "Handle.h"
#include <iostream>

using namespace std;

int 
main(void)
{
	Handle h;
	cout << h.read() << endl;
	h.change(6);
	cout << h.read() << endl;
}


