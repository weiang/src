/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月18日 星期三 11时45分24秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &, int, int);
void print(const vector<int> &);

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
	cout << "Before sort: ";
	print(arr);
	quick_sort(arr, 0, arr.size() - 1);
	cout << "After sort: ";
	print(arr);
	return 0;
}
