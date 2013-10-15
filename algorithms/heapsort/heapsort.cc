/*************************************************************************
	> File Name: heapsort.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月17日 星期二 16时41分58秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

inline int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
//	cout << "left = " << 2 * i + 1 << endl;
	return 2 * i + 1;
}

int right(int i)
{
//	cout << "right = " << 2 * i + 2 << endl;
	return 2 * i + 2;
}

void max_heapify(vector<int> &arr, int heapSize, int i)
{
	int l = left(i);
	int r = right(i);
	int max = i;
	
	if (heapSize > l)
		if (arr[l] > arr[max])
			max = l;
	if (heapSize > r)
		if (arr[r] > arr[max])
			max = r;
	if (max != i) {
		int tmp = arr[max];
		arr[max] = arr[i];
		arr[i] = tmp;
		max_heapify(arr, heapSize, max);
	}
}

void build_max_heap(vector<int> &arr, int heapSize)
{
	int i = heapSize / 2 - 1;
	for (; i >= 0; i --)
		max_heapify(arr, heapSize, i);
}


void heap_sort(vector<int> &arr)
{
	int heapSize = arr.size();
	build_max_heap(arr, heapSize);
	while (heapSize != 1) {
		int tmp = arr[0];
		arr[0] = arr[heapSize - 1];
		arr[heapSize - 1] = tmp;
		heapSize --;
		max_heapify(arr, heapSize, 0);
	}
}

int heap_maximum(const vector<int> &arr)
{
	return arr[0];
}

void insert(vector<int> &arr, int key)
{
	arr.push_back(key);
	int c = arr.size() - 1;
	
	int p = parent(c);
	while (key > arr[p]) {
		arr[c] = arr[p];
		c = p;
		p = parent(c);
		if (c == 0)
			break;
	}
	arr[c] = key;
}

int extract(vector<int> &arr)
{
	int tmp = arr[0];
	arr[0] = arr[arr.size() - 1];
	max_heapify(arr, arr.size() - 1, 0);
	arr.pop_back();

	return tmp;
}

void increase_key(vector<int> &arr, int x, int k)
{
	int i;
	for (i = 0; i != arr.size(); i ++) 
		if (arr[i] == x)
			arr[i] = k;
	int p = parent(i);
	while (i != 0 && arr[p] < k) {
		arr[i] = arr[p];
		i = p;
		p = parent(i);
	}
	arr[i] = k;
}

void build_max_heap_with_insert(vector<int> &arr, int heapSize)
{
	for(int i = 1; i != heapSize; i ++) 
		insert(arr, arr[i]);
}

void print(const vector<int>& arr)
{
	cout << "Heap: " << endl;
	int i = 0;
	int	k = 0;
	int m = 1;
	while (i != arr.size()) {
		cout << arr[i] << " ";
		k ++;
		if(k == m) {
			k = 0;
			m *= 2;
			cout << endl;
		}
		i ++;
	}
	cout << endl;
}


			

