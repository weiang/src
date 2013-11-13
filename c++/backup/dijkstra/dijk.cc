/*************************************************************************
	> File Name: dijk.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年10月25日 星期五 01时52分38秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "priorityQueue.h"
#include <cstdio>
#include <cstdlib>
#include "dijk.h"

using namespace std;

template <typename Object>
float Dijk<Object>::shortestPathAlgorithm(int source, int des)
{
	pqNode s;
	
	s.predecessor = source;
	s.name = source;
	s.value = 0.0;
	PriorityQueue<pqNode> pq;
	pq.insert(s);

	while (true) {
		pqNode j = pq.minPriority();
		if (j.name == des) {
			return j.value;
		}
		closeSet.push_back(j);
		vector<int> adjacentVertices = g.neighbors(j.name);
		for (int i = 0; i != adjacentVertices.size(); i ++) {
			pqNode p;
			p.name = i;
			if (!pq.isContain(p)) {
				p.value = j.value + g.getEdgeValue(j.name, p.name);
				p.predecessor = j.name;
				pq.insert(p);
			}
			else {
				pqNode q = pq.find(p);
				float newVal = j.value + g.getEdgeValue(j.name, p.name);
				if (q.value > newVal) {
					q.predecessor = j.name;
					pq.decreasePriority(q, newVal);
				} 
			}				
		}
	}
}

template<typename Object>
void Dijk<Object>::showPath(int x, int y)
{
	if (x == y)
		cout << mapping[x];
	int i;
	for (i = 0; i != closeSet.size(); i ++) 
		if (closeSet[i].name == y)
			break;
	showPath(x, closeSet[i].predecessor);
	cout << "-" << mapping[y];
}

template <typename Object>
int Dijk<Object>::index(const Object& x) const
{
	for (int i = 0; i != mapping.size(); i ++) 
		if (x == mapping[i])
			return i;
	return -1;
}

/* 
 * Constructor 
 * rhs represents all vertices in graph
 * vertexNum is the vertex number of the graph
 * density is the number of edges / number of vertices
 * limit is the bigget value of edges in graph
 */ 
template <typename Object>
Dijk<Object>::Dijk(const std::vector<Object>&rhs, float density, float limit) : g(rhs.size()), mapping(rhs)
{
	int vertexNum = rhs.size();
	int edgeNum = static_cast<int>(vertexNum * density);
	for (int i = 0; i != edgeNum; i ++) {
		int x, y;
		float val;
		edgeGen(x, y, vertexNum, limit);
		g.addEdge(x, y, val);
	}
}

/* 
 * Shortest path between x and y
 */
template <typename Object>
float Dijk<Object>::path(const Object& x, const Object& y)
{
	int source = index(x);
	int des = index(y);
	float result;

	result = shortestPathAlgorithm(source, des);
	cout << "Short Path from " << x << " to " << y << ": ";
	showPath(source, des);
	return result;
}


/*
 * Generate random edge
 */
void edgeGen(int& x, int& y, int size, float& limit)
{
 	x = rand() % size;
 	while ((y = rand() % size) == x)
 		;
 	limit = static_cast<float>(rand()) / RAND_MAX * limit;
}

