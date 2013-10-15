/*************************************************************************
	> File Name: countingsort.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月19日 星期四 19时29分42秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(const vector<int> &arr, int limit)
{
	vector<int> cnt(limit);
	for(int i = 0; i != limit; i ++) 
		cnt[i] = 0;
	for (int i = 0; i != arr.size(); i ++) 
		cnt[arr[i]] ++;
	
	/* Print arr cnt */
/*	
	for (int i = 0; i != cnt.size(); i ++)
		cout << cnt[i] << " ";
	cout << endl;
*/
	for (int i = 1; i != limit; i ++)
		cnt[i] += cnt[i - 1];
/*	
	for (int i = 0; i != cnt.size(); i ++)
		cout << cnt[i] << " ";
	cout << endl;
*/
	vector<int> result(arr.size());
	for (int i = arr.size() - 1; i != -1; i --) {
		result[cnt[arr[i]] - 1] = arr[i];
		cnt[arr[i]] --;
	}
/*
	for (int i = 0; i != result.size(); i ++)
		cout << result[i] << " ";
	cout << endl;
*/
	return result;
}

