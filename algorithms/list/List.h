#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

template <typename Object>
class List {
	private:
		struct Node;
	
	public:
		List() : theSize(0) 
		{ 
			head.pre = &head; 
			head.next = &head;
		}
		
		List(const List& rhs)
		{
			head.pre = head.next = &head;
			*this = rhs;
		}
		~List() { clear(); }

		int size() const { return theSize; }
		void clear()
		{
			struct Node *n = head.next;
			while (n != &head) {
				struct Node *oldHead = n;
				n = n -> next;
				delete oldHead;
			}
			theSize = 0;
			head.next = &head;
			head.pre = &head;
		}
		
		bool empty() const 
		{
			return head.pre == head.next;
		}

		void push_back(const Object& ele)
		{
			struct Node *n = new struct Node;
			n -> element = ele;
			struct Node *last = head.pre;
			last -> next = n;
			head.pre = n;
			n -> pre = last;
			n -> next = &head;
			theSize ++;
		}

		void pop_back()
		{
			if (empty())
				return;
			struct Node *last = head.pre;
			head.pre = last -> pre;
			last -> pre -> next = &head;
			delete last;
			theSize --;
		}

		void push_front(const Object& ele)
		{
			struct Node *n = new struct Node;
			n -> element = ele;
			n -> pre = &head;
			n -> next = head.next;
			head.next -> pre = n;
			head.next = n;
			theSize ++;
		}

		void pop_front()
		{
			if (empty())
				return;
			struct Node *first = head.next;
			head.next = first -> next;
			first -> next = &head;
			delete first;
			theSize --;
		}

		Object& front()
		{
			return head.next -> element;
		}
		const Object& front() const
		{
			return head.next -> element;
		}

		Object& back() 
		{
			return head.pre -> element;
		}
		const Object& back() const
		{
			return head.pre -> element;
		}
	
		Object& at(int index)
		{
			struct Node *n = head.next;
			for (int i = 1; i < index && i <= size(); i ++) 
					n = n -> next;
			return n -> element;
		}

		void printList() const
		{
			if (empty()) 
				std::cout << "Empty List" << std::endl;
			else {
				struct Node *n = head.next;
				while (n != &head) {
					std::cout << n -> element << " ";
					n = n -> next;
				}
				std::cout << std::endl;
			}
		}

		class const_Iterator {
			public:
				const_Iterator(struct Node *itr = NULL) : theIterator(itr) {}
				const_Iterator(const const_Iterator& rhs) : theIterator(rhs.theIterator) {}

				const_Iterator& operator++()
				{
					theIterator = theIterator -> next;
					return *this;
				}
				
				const_Iterator& operator++(int)
				{
					const_Iterator old = *this;
					++ (*this);
					return old;
				}

				const Object& operator*() const
				{
					return theIterator -> element;
				}

				bool operator!=(const const_Iterator& rhs) const
				{
					return rhs.theIterator != theIterator;
				}
				bool operator==(const const_Iterator& rhs) const
				{
					return rhs.theIterator == theIterator;
				}

				const_Iterator& operator=(const const_Iterator& rhs) 
				{
					if (this != &rhs)
						theIterator = rhs.theIterator;
					return *this;
				}

			private:
				struct Node *theIterator;

				friend class List<Object>;
		};

		class Iterator : public const_Iterator {
			public:
				Iterator(struct Node *itr = NULL) : const_Iterator(itr) { }
				Iterator(const Iterator& itr) : const_Iterator(itr.theIterator) { }
				
				const Object& operator*() const
				{
					return const_Iterator::theIterator -> element;
				}
				
				Object& operator*()
				{
					return const_Iterator::theIterator -> element;
				}

				Iterator& operator++()
				{
					const_Iterator::theIterator = const_Iterator::theIterator -> next;
					return *this;
				}

				Iterator& operator++(int)
				{
					Iterator old = *this;
					++ (*this);
					return old;
				}

			private:
				friend class List<Object>;
		};

		Iterator begin() 
		{
			return Iterator(head.next);
		}
		
		const_Iterator begin() const
		{
			return const_Iterator(head.next);
		}

		Iterator end()
		{
			return Iterator(&head);
		}
		
		const_Iterator end() const
		{
			return const_Iterator(&head);
		}
	
		List& operator=(const List& rhs)
		{
			if (this != &rhs) {
				clear();
				if (!rhs.empty()) {
					theSize = rhs.size();
					struct Node *n = rhs.head.next;
					int i = 0;
					while (i != rhs.size()) {
						push_back(n -> element);
						n = n -> next;
						i ++;
					}
				}
			}
			return *this;
		}

		Iterator insert(Iterator pos, const Object& ele)
		{
			struct Node *n = new struct Node;
			struct Node *p = pos.theIterator;
			n -> element = ele;
			n -> pre = p -> pre;
			n -> next = p;
			p -> pre -> next = n;
			p -> pre = n;
			theSize ++;
			return Iterator(n);
		}


	private:
		struct Node {
			Object element;
			struct Node *pre, *next;
		};
		
		struct Node head;
		int theSize;
};

#endif // _LIST_H_

