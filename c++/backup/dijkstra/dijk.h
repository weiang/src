#ifndef _DIJK_H_
#define _DIJK_H_

#include <iostream>
#include <vector>
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
		Dijk(const std::vector<Object>& rhs, float density, float limit);
		~Dijk() { }

		/* 
		 * Shortest path between x and y
		 */
		float path(const Object& x, const Object& y);
		 			
		void path_size(const Object& x, const Object& y)
		{
			std::cout << "Distance = " << path(x, y) << std::endl;
		}
};	


/*
 * Generate random edge
 */
void edgeGen(int& x, int& y, int size, float& limit);

#endif // _DIJK_H_