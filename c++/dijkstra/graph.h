#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>

static const float F_INFINIT = 100000.0;

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

/*
 * Implementation of class Graph
 */

/*
 * Constructor
 * Using vertices array to initialize Graph
 */
Graph::Graph(int verticesNum) : edgeNumber(0)
{
for (int i = 0; i != verticesNum; i ++) {	// Build vertices array
	VertexNode v;
	v.name = i;
	v.first.next = NULL;
	vertices.push_back(v);
	}
}
		
/*
 * dstructor 
 */
Graph::~Graph()
{
	for (int i = 0; i != getVertices(); i ++) {
		EdgeNode *enode = vertices[i].first.next;
		EdgeNode *tmp;
		while (enode != NULL) {
			tmp = enode -> next;
			delete enode;
			enode = tmp;
		}
	}
}

/* 
 * Test whether edge(i, j) is included in graph
 */
bool Graph::isAdjacent(int i, int j) const
{
	EdgeNode *enode = vertices[i].first.next;
	while (enode != NULL) {
		if (enode -> name == j)
			return true;
			enode = enode -> next;
		}
	return false;
}


	
/*
 * List all vertices which is adjacent to vertex x
 */
void Graph::listNeighbors(int x) const
{
	EdgeNode *enode = vertices[x].first.next;
	
	if (enode == NULL) {
		std::cout << "There is no vertex adjacent to " << x << std::endl;
		return;
	}
	std::cout << "These are vertices adjacent to " << x << " : " << std::endl;
	while (enode != NULL) {
		 std::cout << enode -> name << " ";
		 enode = enode -> next;
	}
	std::cout << std::endl;
}

/*
 * Return a vector that cotains x's adjacent vertices' number
 */
std::vector<int> Graph::neighbors(int x) const 
{
	std::vector<int> result;
	EdgeNode *enode = vertices[x].first.next;

	while (enode != NULL) {
		result.push_back(enode -> name);
		enode = enode -> next;
	}
	return result;
}

/*
 * Add edge between vertex x and y into graph
 */
void Graph::addEdge(int x, int y, float val)
{	
	if (x != y) {	// Illegal to insert edge(x, x)
		if (!isAdjacent(x, y)) {
			/* Insert vertex x into y's adjacent vertices */ 
			EdgeNode *enode = new EdgeNode;
			enode -> name = x;
			enode -> value = val;
			enode -> next = vertices[y].first.next;
			vertices[y].first.next = enode;
			
			/* Insert vertex y into x's adjacent vertices */
			enode = new EdgeNode;
			enode -> name = y;
			enode -> value = val;
			enode -> next = vertices[x].first.next;
			vertices[x].first.next = enode;
			
			edgeNumber ++;
		}
	}
}

/*
 * Delete edge between vertex x and y from graph
 */
void Graph::deleteEdge(int x, int y)
{
	if (isAdjacent(x, y)) {	// There is a edge(x, y)
		/* Delete edge(x, y) */
		EdgeNode *enodePre = &vertices[x].first;
		EdgeNode *enode = enodePre-> next;
		while (enode != NULL) {
			if (enode -> name == y) {
				enodePre -> next = enode -> next;
				delete enode;
				break;
			}
			enodePre = enode;
			enode = enode -> next;	
		}

		/* Delete edge(y, x) */
		enodePre = &vertices[y].first;
		enode = enodePre -> next;
		while (enode != NULL) {
			if (enode -> name == x) {
				enodePre -> next = enode -> next;
				delete enode;
				break;
			}
			enodePre = enode;
			enode = enode -> next;
		}
		edgeNumber --;
	}
}

/*
 * Get the value of edge(x, y)
 * Return F_INFINIT if no edge(x, y) exists
 */
float Graph::getEdgeValue(int x, int y) const
{
	if (isAdjacent(x, y)) {
		EdgeNode *enode = vertices[x].first.next;
		while (enode != NULL) {
			if (enode -> name == y)
				return enode -> value;
			enode = enode -> next;
		}
	}
	return F_INFINIT;
}
		
/*
 * Set the value of edge(x, y)
 * If there is no edge(x, y) existing, doing nothing
 */
void Graph::setEdgeValue(int x, int y, float val)
{
	if (isAdjacent(x, y)) {
		/* Set x's y edge value */
		EdgeNode *enode = vertices[x].first.next;
		while (enode -> name != y)
			enode = enode -> next;
		enode -> value = val;
		
		/* Set y's x edge value */
		enode = vertices[y].first.next;
		while (enode -> name != x)
			enode = enode -> next;
		enode -> value = val;
	}
}



// int main(void)
// {
// 	int cnt;
// 	cin >> cnt;
	
// 	Graph g(cnt);

// 	return 0;
// }
		
#endif // _GRAPH_H_

