/*************************************************************************
	> File Name: quicksort.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月18日 星期三 11时35分56秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
	int i = left - 1;
	int key = arr[right];

	for (int j = left; j != right; j ++) {
		if (arr[j] <= key) {
			i ++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int tmp = arr[i + 1];
	arr[i + 1] = key;
	arr[right] = tmp;
	return i + 1;
}

int partition1(vector<int> &arr, int low, int high)
{
	int key = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= key)
			high --;
		arr[low] = arr[high];
		while (low < high && arr[low] <= key)
			low ++;
		arr[high] = arr[low];
	}
	arr[low] = key;
	return low;
}

void quick_sort(vector<int> &arr, int p, int r)
{
	if (p < r) {
		int q = partition1(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}
}

void print(const vector<int> &arr)
{
	cout << endl;
	for (int i = 0; i != arr.size(); i ++) 
		cout << arr[i] << " ";
	cout <<endl;
}
