/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月26日 星期四 23时28分01秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> l;

	l.printList();
	for (int i = 0; i != 15; i ++)
		l.push_back(i);
	l.printList();
	cout << "Size: " << l.size() << endl;
	cout << "Index 7: " << l.at(7) << endl;
	cout << "Front: " << l.front() << endl;
	cout << "Back: " << l.back() << endl;

	l.pop_back();
	l.printList();
	l.pop_front();
	l.printList();
	l.push_back(14);
	l.printList();
	l.push_front(0);
	l.printList();
	
	List<int> l2(l);
	l2.printList();

	List<int>::Iterator itr = ++ l.begin();
	l.insert(itr, 300);
	l.printList();
	cout << "Using Iterator: " << endl;
	for (List<int>::const_Iterator itr = l.begin(); itr != l.end(); ++ itr) {
		cout << *itr << " ";
	}
	cout << endl;
	List<int> l3;
	l3 = l;
	l3.printList();
	l.clear();
	l.printList();

	return 0;
}
