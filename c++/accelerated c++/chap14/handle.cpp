#include "handle.h"
#include <stdexcept>

template <class T>
handle<T>& handle<T>::operator=(const handle& h)
{
	if (&h != this) {
		if (p)
			delete p;
		p = h.p ? h.p -> clone() : 0;
	}
	return *this;
}

template <class T>
handle<T>::operator bool() const
{
	return p;
}

template <class T>
T& handle<T>::operator*() const 
{
	if (p)
		return *p;
	else 
		throw ("Unbounded pointer!");
}

template <class T>
T* handle<T>::operator->() const
{
	if (p)
		return p;
	else
		throw ("Unbounded pointer!");
}


