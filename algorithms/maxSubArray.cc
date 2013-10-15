/*************************************************************************
	> File Name: maxSubArray.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月08日 星期日 13时24分32秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

const int INFINIT = -999999;
using namespace std;

int find_max_crossing_subarray(int &left, int &right, vector<int> &arr)
{
	int mid = (left + right) / 2;

	int sum = 0;
	int left_sum = INFINIT;
	int left_most = mid;
	for (int i = mid; i >= left; i --) {
		sum += arr[i];
		if (left_sum < sum) {
			left_sum = sum;
			left_most = i;
		}
	}

	int right_sum = INFINIT;
	sum = 0;
	int right_most = mid;
	for (int i = mid + 1; i <= right; i ++) {
		sum += arr[i];
		if (right_sum < sum) {
			right_sum = sum;
			right_most = i;
		}
	}
	left = left_most;
	right = right_most;
//	cout << "find_max_crossing_subarray(" << left << ", " << right << ", arr)" 
//		 << " (" << left << ", "<< right << ", " << sum << ")" << endl;
	return right_sum + left_sum;
}

int find_max_subarray(int &left, int &right, vector<int> &arr)
{
//	cout << "find_max_subarray(" << left << ", " << right <<", arr)" << endl;
	/* Base case: only one element */
	if (left == right)
		return arr[left];
	else {
		int mid = (left + right) / 2;
		int midp1 = mid + 1;
		int left_most = left;
		int right_most = right;
		int left_sum = find_max_subarray(left_most, mid, arr);
		int right_sum = find_max_subarray(midp1, right_most, arr);
		int crossing_left = left;
		int crossing_right = right;
//		cout << "crossing_left, crossing_right: " << crossing_left << ", " 
//			 << crossing_right << endl;
		int crossing_sum = find_max_crossing_subarray(crossing_left, crossing_right, arr);

		if (left_sum >= crossing_sum && left_sum >= right_sum) {
			left = left_most;
			right = mid;
			return left_sum;
		}
		else if (crossing_sum >= right_sum) {
			left = crossing_left;
			right = crossing_right;
			return crossing_sum;
		}
		else {
			left = midp1;
			right = right_most;
			return right_sum;
		}
	}
}

int find_max_subarray2(int &left, int &right, vector<int> &arr)
{
	int left_most = left;
	int right_most = right;
	int max = INFINIT;

	for (int i = left; i <= right; i ++) {
		int sum = 0;
		for (int j = i; j <= right; j ++) {
			sum += arr[j];
			if (sum > max) {
				left_most = i; 
				right_most = j;
				max = sum;
			}
		}
	}
	left = left_most;
	right = right_most;
	return max;
}

int main(void)
{
	int cnt;

	cin >> cnt;

	vector<int> arr;
	int i = 0;
	while (i != cnt) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		i ++;
	}

	int left = 0;
	int right = arr.size() - 1;
	int result = find_max_subarray(left, right, arr);
	cout << "Result: sum = " << result << " i, j: " << left << ", " << right << endl;

	int result2 = find_max_subarray2(left, right, arr);
	cout << "Resutl2: sum = " << result2 << " i, j: " << left << ", " << right << endl;
	return 0;
}


