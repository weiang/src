#include <iostream>
#include "AVLtree.h"
#include <string>

using namespace std;

int main(void)
{
	int cnt;

	cin >> cnt;

	vector<int> a;
	while (cnt > 0) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		cnt --;
	}

	AVLtree<int> tree(a);
	tree.showWithDepth();
	tree.insert(14);
	tree.showWithDepth();
	tree.insert(a[0]);
	tree.remove(14);
	tree.showWithDepth();

	cin >> cnt;
	vector<string> b;
	while (cnt != 0) {
		string tmp;
		cin >> tmp;
		b.push_back(tmp);
		cnt --;
	}
//	cout << "b.size() = " << b.size() << endl;
	AVLtree<string> tree2(b);
	tree2.showWithDepth();
	tree2.insert("weiang");
	tree2.showWithDepth();
	cout << "Remove 'weiang':";
 	tree2.remove("weiang");
	tree2.showWithDepth();
	tree2.insert(b[0]);
	tree2.showWithDepth();

	return 0;
}
