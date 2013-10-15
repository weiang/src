/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月19日 星期四 19时42分04秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(const vector<int> &, int);

int main()
{
	int cnt;
	cin >> cnt;

	vector<int> arr;
	while (cnt != 0) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		cnt --;
	}


	cout << "Before sort: " << endl;
	for (int i = 0; i != arr.size(); i ++)
		cout << arr[i] << " ";
	cout << endl;

	arr = counting_sort(arr, 100);
	
	cout << "After sort: " << endl;
	for (int i = 0; i != arr.size(); i ++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

