#ifndef _VECTOR_H_
#define _VECTOR_H_

template <typename Object>
class Vector {
	public:
		Vector(int sz = 0) : theSize(sz), theCapacity(sz + SPARE_SPACE) 
		{
			objects = new Object[size()];
		}

		Vector(const Vector& rhs)  
		{
			operator=(rhs);
		}
		
		~Vector()
		{
			delete[] objects;
		}
		int size() const { return theSize; }
		int capacity() const { return theCapacity; }
		bool empty() const { return size() == 0; }
		const Object& front() const { return objects[0]; }
		Object& front() { return objects[0]; }
		const Object& back() const { return objects[size() - 1]; }
		Object& back() { return objects[size() - 1]; }
	
		void push_back(const Object&);
		void pop_back() { theSize --;}
		
		void clear();
		Vector& operator=(const Vector& rhs);
		const Object& operator[](int index) const 
		{
			return objects[index];
		}
		Object& operator[](int index) 
		{
			return objects[index];
		}
		const Object& at(int index) const
		{
			if (index < size())
				return objects[index];
		}
		Object& at(int index)
		{
			if (index < size())
				return objects[index];
		}


		typedef Object * iterator;
		typedef const Object * const_iterator;

		const_iterator begin() const
		{
			return &objects[0];
		}
		iterator begin() 
		{
			return &objects[0];
		}
		const_iterator end() const
		{
			return &objects[size()];
		}
		iterator end()
		{
			return &objects[size()];
		}
	
		enum { SPARE_SPACE = 16};
	private:
		int theSize;
		int theCapacity;
		Object *objects;

		void reserve(int);
};

#endif // _VECTOR_H_
