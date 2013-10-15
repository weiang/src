/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月17日 星期二 17时04分06秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>
#include "heapsort.h"

using namespace std;

int main()
{
	int cnt;
	
	cin >> cnt;
	vector<int> arr;
	while (cnt != 0) {
		int tmp;
		cin >> tmp;

		insert(arr, tmp);
		cnt --;
	}	

//	build_max_heap_with_insert(arr, arr.size());
	print(arr);
	/* Test for insert() */
//	cout << "Before insert: " << endl;
//	print(arr);
//	insert(arr, 11);
//	cout << "After insert(5) " << endl;
//	print(arr);

	/* Test for extract() */
	cout << "After extract: ";
	cout << extract(arr) << endl;
	print(arr);
	
	/* Test for increase_key() */
	cout << "Test increase_key(arr, 11, 20) " << endl;
	increase_key(arr, 11, 20);
	print(arr);

	/* Test for heap_sort() */
	cout << "Before sort: " << endl;
	print(arr);
	heap_sort(arr);
	cout << "\nAfter sort: " << endl;
	print(arr);


	return 0;
}


