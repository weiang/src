/*************************************************************************
	> File Name: radixsort.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Sep 19, 2013  9:24:27 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(const vector<int> &);

void radix_sort(vector<int> &arr, int pass)
{
	int w = 1;
	vector<int> cnt(10);
	for (int i = 0; i != pass; i ++) {
		for (int k = 0; k != 10; k ++)
			cnt[k] = 0;
		for (int j = 0; j != arr.size(); j ++) {
			cnt[(arr[j] / w) % 10] ++;
		}
		for (int j = 1; j != 10; j ++)
			cnt[j] += cnt[j - 1];
/*		cout << "Cnt: ";
		print(cnt);
*/		vector<int> result(arr.size());
		for (int j = arr.size() - 1; j != -1; j --) { 
			result[cnt[(arr[j] / w) % 10] - 1] = arr[j];
			cnt[(arr[j] / w) % 10] --;
		}
		for (int j = 0; j != arr.size(); j ++)
			arr[j] = result[j];
		w *= 10;
/*		cout << "Result: ";
		print(result);
*/	}
}

void print(const vector<int> &arr)
{
	cout << endl;
	for (int i= 0; i != arr.size(); i ++)
		cout << arr[i] << " ";
	cout << endl;
}


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

	int max_bit = 1;
	for (int i = 0; i != arr.size(); i ++) {
		int bits = 0;
		int tmp = arr[i];
		while (tmp != 0) {
			bits ++;
			tmp /= 10;
		}
		if (bits > max_bit)
			max_bit = bits;
	}

	cout << "Max_bit = " << max_bit << endl;
	cout << "Before sort: " << endl;
	print(arr);
	radix_sort(arr, max_bit);
	cout << "After sort: " << endl;
	print(arr);

	return 0;
}


