/*************************************************************************
	> File Name: array.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Aug 01, 2013 12:42:59 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class array {
	public:
		T& operator[](int index);

	private:
		enum { size = 100 };
		T a[size];
};

template <class T>
T& array<T>::operator[](int index)
{
	if (index >=0 && index < size)
		return a[index];
}

int
main(void)
{
	array<float> fa;
	fa[0] = 1.414;
	return 0;
}

