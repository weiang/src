/*************************************************************************
	> File Name: cut_rod.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月20日 星期日 23时01分37秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int recursive_cut_rod(const vector<int>& weight, int length)
{
	if (length == 0)
		return 0;
	int q = -1;
	for (int i = 1; i <= length; i ++) {
		int cut = weight[i] + recursive_cut_rod(weight, length - i);
		q = q > cut ? q : cut;
	}
	return q;
}

int memoized_cut_rod_aux(const vector<int>& weight, int length, vector<int>& m)
{	
	if (m[length] >= 0)
		return m[length];
	int q = -1;
	for (int i = 1;i <= length; i ++) {
		int cut;
		q = (q > (cut = weight[i] + memoized_cut_rod_aux(weight, length - i, m)))
			? q : cut;
	}
	m[length] = q;
	return q;	
}

int memoized_cut_rod(const vector<int>& weight, int length, vector<int>& m)
{
	for (int i = 0; i != m.size(); i ++)
		m[i] = -1;
	if (m.size() < length) {
		for (int i = 0; i <= length - m.size(); i ++)
			m.push_back(-1);
	}
	m[0] = 0;
	return memoized_cut_rod_aux(weight, length, m);
}
int buttom_up_cut_rod(const vector<int>& weight, int length, vector<int>& m)
{
	m[0] = 0;
	for (int i = 1; i <= length; i ++) {
		int q = -1;
		int cut;
		for (int j = 1; j <= i; j ++) {
			q = q > (cut = weight[j] + m[i - j]) ? q : cut;
		}
		m[i] = q;
	}
	return m[length];
}

int memoized_cut_rod_solution_aux(const vector<int>& w, int length, vector<int>& m, vector<int>& r)
{
	if (m[length] >= 0)
		return m[length];
	int q = -1;
	int t = 0;
	for (int i = 1; i <= length; i ++) {
		int cut = w[i] + memoized_cut_rod_solution_aux(w, length - i, m, r);
		if (cut > q) {
			q = cut;
			t = i;
		}
	}
	m[length] = q;
	r[length] = t;
	return q;
}

int memoized_cut_rod_solution(const vector<int>& w, int length, vector<int>& m, vector<int>& r)
{
	for (int i = 0; i != m.size(); i ++)
		m[i] = -1;
	if (m.size() < length) {
		for (int i = 0; i <= length - m.size(); i ++)
			m.push_back(-1);
	}
	if (r.size() < length)
		for (int i = 0; i <= length - r.size(); i ++)
			r.push_back(0);
	m[0] = 0;
	return memoized_cut_rod_solution_aux(w, length, m, r);
}

void show_result(const vector<int>& r, int length)
{
	if (length == 0)
		return;
	show_result(r, length - r[length]);
	cout << r[length] << " ";
}
int main(void)
{
	int cnt;
	cin >> cnt;
	vector<int> w;
	w.push_back(0);
	for (int i = 1; i <= cnt; i ++) {
		int weight;
		cin >> weight;
		w.push_back(weight);
	}
	int length; 
	cin >> length;
	if (length > cnt) {
		for (int i = 0; i < length - cnt; i ++)
			w.push_back(0);
	}

	vector<int> m;
//	cout << "length = " << length << endl;
	for (int i = 0; i <= length; i ++)
		m.push_back(0);
	vector<int> r;
	for (int i = 0; i <= length; i ++)
		r.push_back(0);
	int result;
/*	result = recursive_cut_rod(w, length);
	cout << result << endl;
	result = memoized_cut_rod(w, length, m);
	cout << result << endl;
	result = buttom_up_cut_rod(w, length, m);
	cout << result << endl;
*/
	result = memoized_cut_rod_solution(w, length, m, r);
	show_result(r, length);
	cout << endl;
	cout << result << endl;
	return 0;
}

