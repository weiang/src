/*************************************************************************
	> File Name: nestedIteratorStackTest.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Aug 01, 2013 11:24:35 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include "nestedIteratorStack.h"

using namespace std;

int 
main(void)
{
	Stack<int> is;
	for (int i = 0; i < 20; i ++)
		is.push(i);

	cout << "Traverse the whole Stack of INT\n";
	Stack<int>::iterator it = is.begin();
	while (it != is.end()) 
		cout << it ++ << endl;

	cout << "Traverse a portion of the Stack of INT\n";
	Stack<int>::iterator start = is.begin(), end = is.begin();
	start += 5;
	end += 15;
	cout << "Start = " << start << endl;
	cout << "End = " << end << endl;
	while (start != end)
		cout << start ++ << endl;
	return 0;
}
