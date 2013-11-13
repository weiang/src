#include "redBlackTree.h"
#include <iostream>

using namespace std;

int main(void)
{
	RedBlackTree<int> tree(-1);
	int cnt;
	cin >> cnt;
	cout << cnt << endl;
	int tmp;
	cout << "Is empty? " << tree.isEmpty() << endl;
	for (int i = 0; i != cnt; i ++) {
		cin >> tmp;
//		cout << tmp << endl;
		cout << "Insert " << tmp << endl;
		tree.insert(tmp);
		tree.printTree();
	}
	cout << "Is empty? " << tree.isEmpty() << endl;
	cout << "contains test: ";
	cout << tree.contains(22) << " " << tree.contains(8) << endl;
	tree.insert(tmp);
	tree.printTree();
	cout << "Max: " << tree.findMax() << endl;
	cout << "Min: " << tree.findMin() << endl;
	cout << "Find: " << tree.find(22) << " " << tree.find(9) << endl;
	tree.makeEmpty();
	tree.printTree();
	tree.remove(1);
	cout << "Is emtpy? " << tree.isEmpty() << endl;
	return 0;
}