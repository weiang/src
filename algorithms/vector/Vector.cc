/*************************************************************************
	> File Name: Vector.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月25日 星期三 16时31分19秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "Vector.h"

using namespace std;

template <typename Object>
typename Vector<Object>::Vector& Vector<Object>::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		delete [] objects;
		theSize = rhs.size();
		theCapacity = rhs.theCapacity;
		objects = new Object[capacity()];
		for (int i = 0;i != size(); i ++) 
			objects[i] = rhs[i];
	}
	return *this;
}

template <typename Object>
void Vector<Object>::push_back(const Object& o)
{
	if (size() == capacity())
		reverse(capacity() * 2 + 1);
	objects[theSize ++] = o;
}

template <typename Object>
void Vector<Object>::reserve(int sz)
{
	if (sz <= size())
		return;
	Object *oldArray = objects;
	objects = new Object[sz];
	for (int i = 0; i != size(); i ++)
		objects[i] = oldArray[i];
	theCapacity = sz;
	delete[] oldArray;
}



