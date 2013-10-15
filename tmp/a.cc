/*************************************************************************
	> File Name: a.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Aug 22, 2013 11:03:43 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NUM 1 

int main(void)
{
	for (int i = 0; i != NUM; i ++) {
		if (fork() == 0) 
			break;
	}
	while (1)
		;
	return 0;
}
