#ifndef _DIJK_H_
#define _DIJK_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include "graph.h"
#include "priorityQueue.h"


template <typename Object>
class Dijk {
	private:
		Graph g;
		std::vector<Object> mapping;	// Maintain a mapping from integers to Objects
		
		/* 
		 * Internal node of PriorityQueue
		 */
		typedef struct pqNode {
			int name;	// Vertex number
			float value;	// Current short distance to source vertex
			int predecessor;	
	
			pqNode(float val = 0.0) : value(val)
			{
			}

			const bool operator<(const pqNode& b) const
			{
				return value < b.value;
			}

			const bool operator==(const pqNode& a) const
			{
				return name == a.name;
			}

		}pqNode;

		std::vector<pqNode> closeSet;	// Close set

		float shortestPathAlgorithm(int source, int des);

	
		void showPath(int x, int y);

		int index(const Object& x) const;

	
	public:
		/* 
		 * Constructor 
		 * rhs represents all vertices in graph
		 * vertexNum is the vertex number of the graph
		 * density is the number of edges / number of vertices
		 * limit is the bigget value of edges in graph
		 */ 
		Dijk(const std::vector<Object>&rhs, float density, float limit) : g(rhs.size()), mapping(rhs)
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

		~Dijk() { }

		/* 
		 * Shortest path between x and y
		 */
		float path(const Object& x, const Object& y);
	//	float path(Object x, Object y);

		void path_size(const Object& x, const Object& y)
		{
			std::cout << "Distance = " << path(x, y) << std::endl;
		}
	
		/*
		 * Generate random edge
		 */
		static void edgeGen(int& x, int& y, int size, float& limit);

};	

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
		std::vector<int> adjacentVertices = g.neighbors(j.name);
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
		std::cout << mapping[x];
	int i;
	for (i = 0; i != closeSet.size(); i ++) 
		if (closeSet[i].name == y)
			break;
	showPath(x, closeSet[i].predecessor);
	std::cout << "-" << mapping[y];
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
//template <typename Object>


/* 
 * Shortest path between x and y
 */
template <typename Object>
float Dijk<Object>::path(const Object& x, const Object& y)
//float Dijk<Object>::path(Object x, Object y)
{
	int source = index(x);
	int des = index(y);
	float result;

	result = shortestPathAlgorithm(source, des);
	std::cout << "Short Path from " << x << " to " << y << ": ";
	showPath(source, des);
	return result;
}


/*
 * Generate random edge
 */
template <typename Object>
void Dijk<Object>::edgeGen(int& x, int& y, int size, float& limit)
{
 	x = rand() % size;
 	while ((y = rand() % size) == x)
 		;
 	limit = static_cast<float>(rand()) / RAND_MAX * limit;
}

#endif // _DIJK_H_
