/*************************************************************************
	> File Name: test_graph.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年11月02日 星期六 11时32分51秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	Graph g(5);
	g.addEdge(0, 1, 0.5);
	g.addEdge(0, 2, 1.0);
	g.addEdge(1, 4, 1.2);
	g.addEdge(2, 4, 2.4);
	g.addEdge(3, 4, 1.3);

	cout << g.getVertices() << endl;
	cout << g.getEdges() << endl;
	cout << g.isAdjacent(2, 4) << endl;
	cout << g.isAdjacent(0, 4) << endl;

	vector<int> r = g.neighbors(4);
	for (int i = 0; i != r.size(); i ++)
		cout << r[i] << " ";
	cout << g.getEdgeValue(2, 4);
	cout << endl;
	return 0;
}

