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

template<typename T, typename Comparator>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<T, Comparator>& pq)
{
	for (int i = 0; i != pq.size(); i ++)
		out << pq[i] << " ";
	out << std::endl;
	return out;
}

#endif // _PRIORITY_QUEUE_H_



