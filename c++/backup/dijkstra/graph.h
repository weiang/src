#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>

const float F_INFINIT = 100000.0;

/*
 * Graph Class, which is an adjacency list version 
 * Graph nodes are represented with integers.
 */
 class Graph {
	private:
		int	edgeNumber;		// Number of edges
		
		/* 
		 * Internal representation of graph edges 
		 */
		typedef struct EdgeNode {	// Edge 
			float value;		// The value of the edge
			int name;	// The other end of the edge
			EdgeNode *next;	
		} EdgeNode;
		
		
		/*
		 * Internel representation of graph vertices 
		 */
		typedef struct VertexNode {	// Vertex
			int name;	// The name of the vertex
			EdgeNode first;	// Header of edge list which are adjancent to vertex
		} VertexNode;
		
		std::vector<VertexNode> vertices;

	public:

		Graph(int);
		~Graph();
	
		
		/* 
		 *Get graph's vertices number
		 */
		int getVertices() const
		{
			return vertices.size();
		}
		
		/* 
		 * Get graph's edge number
		 */
		int getEdges() const
		{
			return edgeNumber;
		}
		
		bool isAdjacent(int i, int j) const;
		
		
		/*
		 * List all vertices which is adjacent to vertex x
		 */
		void listNeighbors(int x) const;
	

		/*
		 * Return a vector that cotains x's adjacent vertices' number
		 */
		std::vector<int> neighbors(int x) const ;

		/*
 		 * Add edge between vertex x and y into graph
 		 */
		void addEdge(int x, int y, float val);

		/*
 		 * Delete edge between vertex x and y from graph
 		 */
		void deleteEdge(int x, int y);
		
		/*
		 * Get the value of edge(x, y)
		 * Return F_INFINIT if no edge(x, y) exists
		 */
		float getEdgeValue(int x, int y) const;

		/*
		 * Set the value of edge(x, y)
		 * If there is no edge(x, y) existing, doing nothing
		 */
		void setEdgeValue(int x, int y, float val);
	};

#endif // _GRAPH_H_

