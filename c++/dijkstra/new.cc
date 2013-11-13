#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const float F_INFINIT = 100000.0;	// Using to represent infinite distance between two vertices 

#ifndef _GRAPH_H_
#define _GRAPH_H_

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
		cout << "There is no vertex adjacent to " << x << endl;
		return;
	}
	cout << "These are vertices adjacent to " << x << " : " << endl;
	while (enode != NULL) {
		 cout << enode -> name << " ";
		 enode = enode -> next;
	}
	cout << endl;
}

/*
 * Return a vector that cotains x's adjacent vertices' number
 */
vector<int> Graph::neighbors(int x) const 
{
	vector<int> result;
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

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

/*
 * Priority Queue
 */
template <typename T, typename Comparator = std::less<T> >
class PriorityQueue {
	private:
		std::vector<T> priorityQueue;
		Comparator isLessThan;

		/*
		 * Get ith element's parent
		 */
		inline int parent(int i)
		{
			return (i + 1) / 2 - 1;
		}

		/* 
		 * Get ith element's left child if existed
		 */
		inline int leftChild(int i)
		{
			return 2 * i + 1;
		}

		/*
		 * Get ith element's right child if existed
		 */
		inline int rightChild(int i)
		{
			return 2 * i + 2;
		}

		/* 
		 * Percolate ith element down to proper position 
		 * to maintain the priority queue
		 */
		void percolateDown(int i);

		/*
		 * Percolate ith element up to proper position
		 * to maintain the pririty queue
		 */
		void percolateUp(int i);

		/* 
		 * Build priority queue
		 */
		void buildPriorityQueue(); 

	public:
		/*
		 * Default constructor
		 */
		PriorityQueue() { }
		
		PriorityQueue(const std::vector<T>& rhs);
		
		int size() const
		{
			return priorityQueue.size();
		}

		T& top() 
		{
			if (size())
				return priorityQueue[0];
		}

		T minPriority();

		bool isContain(const T& t) const;

		void insert(T& t);

		void decreasePriority(const T& t, float priority);

		void increasePriority(const T& t, float priority);

		T& find(const T& t);
		
		const T& operator[](int i) const;

		T& operator[](int i);
	};

template<typename T, typename Comparator>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<T, Comparator>& pq)
{
	for (int i = 0; i != pq.size(); i ++)
		out << pq[i] << " ";
	out << std::endl;
	return out;
}

#endif // _PRIORITY_QUEUE_H_

/*
 * Implementation of priority Queue
 */

/* 
 * Percolate ith element down to proper position 
 * to maintain the priority queue
 */
template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::percolateDown(int i)
{
	if (leftChild(i) >= size())	// ith element doesn't have any child
		return;
	else if (leftChild(i) < size() && rightChild(i) >= size()) {	// ith element has one child
		if (isLessThan(priorityQueue[leftChild(i)], priorityQueue[i]))
			swap(priorityQueue[leftChild(i)], priorityQueue[i]);
	}
	else {	// ith element has two children
		int minIndex = i;
		if (isLessThan(priorityQueue[leftChild(i)], priorityQueue[rightChild(i)])) 
		minIndex = leftChild(i);
		else 
			minIndex = rightChild(i);
		if (isLessThan(priorityQueue[i], priorityQueue[minIndex]))
			return;
		swap(priorityQueue[i], priorityQueue[minIndex]);
		percolateDown(minIndex);
	}
}

/*
 * Percolate ith element up to proper position
 * to maintain the pririty queue
 */
template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::percolateUp(int i)
{
	if (i == 0)
		return;
	if (isLessThan(priorityQueue[i], priorityQueue[parent(i)])) {
			swap(priorityQueue[i], priorityQueue[parent(i)]);
			percolateUp(parent(i));
	}
}

/* 
 * Build priority queue
 */
template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::buildPriorityQueue()
{
	for (int i = parent(size() - 1); i >= 0; i --)
		percolateDown(i);
}

template <typename T, typename Comparator>
T& PriorityQueue<T, Comparator>::find(const T& t) 
{
	for (int i = 0; i != size(); i ++)
		if (t == priorityQueue[i])
			return priorityQueue[i];
}

template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::PriorityQueue(const vector<T>& rhs)
{
	for (int i = 0; i != rhs.size(); i ++) 
		priorityQueue.push_back(rhs[i]);
	buildPriorityQueue();
}


template <typename T, typename Comparator>
T PriorityQueue<T, Comparator>::minPriority() 
{
	swap(priorityQueue[0], priorityQueue[size() - 1]);
	T result = priorityQueue[size() - 1];
	priorityQueue.pop_back();
	percolateDown(0);
	return result;
}

template <typename T, typename Comparator>
bool PriorityQueue<T, Comparator>::isContain(const T& t) const
{
	for (int i = 0; i != size(); i ++) 
		if (t == priorityQueue[i])
			return true;
	return false;
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::insert(T& t) 
{
	priorityQueue.push_back(t);
	percolateUp(size() - 1);
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::decreasePriority(const T& t, float priority)
{
	T tmp(priority);
	for (int i = 0; i != size(); i ++) {
		if (t == priorityQueue[i]) {
				priorityQueue[i] = tmp;
				percolateUp(i);
				break;
		}
	}
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::increasePriority(const T& t, float priority)
{
	T tmp(priority);
	for (int i = 0; i != size(); i ++) {
		if (t == priorityQueue[i]) {
			priorityQueue[i] = tmp;
			percolateDown(i);
			break;
		}
	}
}

template <typename T, typename Comparator>
const T& PriorityQueue<T, Comparator>::operator[](int i) const
{
	return priorityQueue[i];
}

template <typename T, typename Comparator>
T& PriorityQueue<T, Comparator>::operator[](int i) 
{
	return priorityQueue[i];
}

#ifndef _DIJK_H_
#define _DIJK_H_

struct pqNode;

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
			

			pqNode(float val) : value(val)
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
		for (int i = 0;i != adjacentVertices.size(); i ++) 
			cout << adjacentVertices[i] << " ";
		cout << endl;
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
	cout << g.getVertices() << endl;
	cout << g.getEdges() << endl;
	for (int i = 0; i != g.getVertices(); i ++) {
		vector<int> r = g.neighbors(i);
		for (int j = 0; j != r.size(); j ++) 
			cout << r[j] << " ";
		cout << endl;
	}
//		cout << g.listNeighbors(i) << endl;
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
	cout << "(" << x << ", " << y << ", " << limit << ")" << endl;
}

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
	sp.path(2, 12);	
	return 0;
}


