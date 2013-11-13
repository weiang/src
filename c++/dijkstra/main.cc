#include "graph.h"
#include "priorityQueue.h"
#include "dijk.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int cnt;
	cin >> cnt;

	vector<int> v;
	while (cnt) {
		int s;
		cin >> s;
		v.push_back(s);
		cnt --;
	}
	float limit = 5.0;
	float d = 0.5;

	Dijk<int> sp(v, d, limit);
	sp.path(*v.begin(), *(v.end() - 1));
	return 0;
}
