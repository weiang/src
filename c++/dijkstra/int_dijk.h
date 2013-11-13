#ifndef _INT_DIJK_H_
#define _INT_DIJK_H_

#include <iostream>
#include <vector>
#include "graph.h"
#include "priorityQueue.h"

class Dijk {
	private:
		Graph g;
		std::vector<int> mapping;	// Maintain a mapping from integers to Objects
		
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

		int index(int x) const;

		/*
		 * Generate random edge
		 */
		static void edgeGen(int& x, int& y, int size, float& limit);

	public:
		/* 
		 * Constructor 
		 * rhs represents all vertices in graph
		 * vertexNum is the vertex number of the graph
		 * density is the number of edges / number of vertices
		 * limit is the bigget value of edges in graph
		 */ 
		Dijk(const std::vector<int>&rhs, float density, float limit) : g(rhs.size()), mapping(rhs)
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
		float path(int x, int y);
	//	float path(Object x, Object y);

		void path_size(int x, int y)
		{
			std::cout << "Distance = " << path(x, y) << std::endl;
		}
};	



#endif // _INT_DIJK_H_
