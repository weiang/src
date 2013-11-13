#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <iostream>
#include <vector>

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
PriorityQueue<T, Comparator>::PriorityQueue(const std::vector<T>& rhs)
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


// typedef struct pqNode {
// 	int name;	// Vertex number
// 	float value;	// Current short distance to source vertex
// 	int predecessor;	
	
// 	const bool operator<(const pqNode& b) const
// 	{
// 		return value < b.value;
// 	}

// 	const bool operator==(const pqNode& a) const
// 	{
// 		return name == a.name;
// 	}

// }pqNode;

// ostream& operator<<(ostream& out, const pqNode& q)
// {
// 	out << q.value << " ";
// 	return out;
// }

// int main()
// {
// 	int cnt;
// 	cin >> cnt;
// 	int i = 0;
// 	vector<pqNode> a;
// 	while (cnt != 0) {
// 		float f;
// 		cin >> f;
// 		pqNode p;
// 		p.value = f;
// 		p.name = i ++;
// 		a.push_back(p);
// 		cnt --;
// 	}
// 	PriorityQueue<pqNode, less<pqNode> > pq(a);
// 	cout << pq;
// 	pqNode p;
// 	p.value = 1.5;
// 	p.name = i;
// 	pq.insert(p);
// 	cout << pq;
// 	pq.minPriority();
// 	cout << pq;
// 	return 0;
// }

template<typename T, typename Comparator>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<T, Comparator>& pq)
{
	for (int i = 0; i != pq.size(); i ++)
		out << pq[i] << " ";
	out << std::endl;
	return out;
}

#endif // _PRIORITY_QUEUE_H_



