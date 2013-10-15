/*************************************************************************
	> File Name: 4_7.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 24, 2013  6:31:37 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "./stash/stash.h"

using namespace std;

int
main(void)
{
	stash s;
	s.init(sizeof(double));

	for (int i = 0; i < 25; i ++) {
		double a = i * 1.0;
		s.add(&a);
	}

	for (int i = 0; i < 25; i ++) 
		cout << "s[" << i << "] = " 
			<< *(double *)s.fetch(i) << endl;
	return 0;
}

