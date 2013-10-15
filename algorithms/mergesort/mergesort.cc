/*
 * Implementation of merge sorting algorithms
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Merge two sorted subarray of arr into one sorted array 
 * using tmpArray as buffer, first subarry begins at index 
 * left, second subarray begins at index right, index end
 * indicates the end of arr
 */  
template <typename T>
void merge(vector<T>& arr, vector<T>& tmpArray, int left, int right, int end)
{
	int leftEnd = right - 1;	// First subarray's last element's index
	int tmpIndex = left;
	int i = left;

	while (left <= leftEnd && right <= end) 
		if (arr[left] < arr[right])
			tmpArray[tmpIndex ++] = arr[left ++];
		else 
			tmpArray[tmpIndex ++] = arr[right ++];
	while (left <= leftEnd)
		tmpArray[tmpIndex ++] = arr[left ++];
	while (right <= end) 
		tmpArray[tmpIndex ++] = arr[right ++];
	for (; i <= end; i ++)
	       arr[i] = tmpArray[i];
}

/* 
 * Recursive merge sort function that sort elements of 
 * arr indexed from left to right, using tmpArray as buffer 
 */
template <typename T>
void mergeSort(vector<T>& arr, vector<T>& tmpArray, int left, int right)
{
	int center = (left + right) / 2;
	
	if (left < right) {
		mergeSort(arr, tmpArray, left, center);
		mergeSort(arr, tmpArray, center + 1, right);
		merge(arr, tmpArray, left, center + 1, right);
	}
}

/*
 * Drive function that uses an unsorted array as only arguement
 */
template <typename T>
void mergeSort(vector<T>& arr)
{
	vector<T> tmpArray(arr.size());
	int end = arr.size() - 1;
	mergeSort(arr, tmpArray, 0, end);
}

int main()
{
	int n;
	cin >> n;
	int tmp;
	vector<int> arr;
	while (cin >> tmp)
		arr.push_back(tmp);
	mergeSort(arr);
	for (int i = 0; i != arr.size(); i ++) 
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
