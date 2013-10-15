/*************************************************************************
	> File Name: auto_ptr.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Fri, Aug 02, 2013 12:40:38 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <memory>
#include <cstddef>

using namespace std;

class TraceHeap {
	public:
		TraceHeap(int ii) : i(ii) { }
		static void *operator new(size_t sz) 
		{
			void *p = ::operator new(sz);
			cout << "Allocating TraceHeap object on the heap " 
				 << "at address " << p << endl;
			return p;
		}

		static void operator delete(void *p) 
		{
			cout << "Deleting TraceHeap object at address " << p << endl;
			::operator delete(p);
		}

		int get_value() const 
		{
			return i;
		}

	private:
		int i;
};

int 
main()
{
	auto_ptr<TraceHeap> my_object(new TraceHeap(5));
	cout << my_object -> get_value() << endl;
	return 0;
}
