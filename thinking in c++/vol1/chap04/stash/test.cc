/*************************************************************************
	> File Name: test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 24, 2013  6:37:42 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "stash.h"

int 
main(void)
{
	stash a;
	a.init(sizeof(int));
	int b = 2;

	a.add(&b);
	cout << *(int *)a.fetch(0) << endl;
	return 0;
}
