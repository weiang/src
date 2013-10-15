#ifndef NESTEDITERATORSTACK_H_
#define NESTEDITERATORSTACK_H_

#include <iostream>
#include <string>

template <class T>
class Stack {
	public:
		Stack() : top(0) { }
		void push(const T& t) 
		{
			if (top < size)
				stack[top ++] = t;
			else 
				std::cout << "Stack full" << std::endl;
		}

		T pop() 
		{
			if (top > 0)
				return stack[-- top];
		}

		/* Nested iterator */
		friend class iterator;
		class iterator {
			public:
				iterator(Stack<T>& is) : s(is), index(0) { }
				iterator(Stack<T>& is, bool) : s(is), index(is.top) { }
				
				T current() const 
				{
					return s.stack[index];
				}

				T  operator++() // prefix
				{
					if (index + 1 < s.top)
						return s.stack[++ index];
				}

				T operator++(int) // postfix
				{
					if (index < s.top)
						return s.stack[index ++];
				}

				iterator& operator+=(int cnt)
				{
					if (index + cnt < s.top)
						index += cnt;
					return *this;
				}

				bool operator==(const iterator& rv) const 
				{
					return index == rv.index;
				}

				bool operator!=(const iterator& rv) const
				{
					return index != rv.index;
				}

				friend std::ostream& operator<<(std::ostream& os, const iterator& it)
				{
					return os << it.current();
				}
		
			private:
				int index;
				Stack& s;
		};
		
		iterator begin() 
		{
			return iterator(*this);
		}

		iterator end() 
		{
			return iterator(*this, true);
		}

	private:
		const static int size = 100;
		T stack[size];
		int top;
};

#endif // NESTEDITERATORSTACK_H_
