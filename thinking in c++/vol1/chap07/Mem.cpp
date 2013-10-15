/*************************************************************************
	> File Name: Mem.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  2:01:16 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstring>
#include "Mem.h"

using namespace std;

void
Mem::ensureMinsize(int minsize)
{
	if (size < minsize) {
		byte *newmem = new byte[minsize];
		memset(newmem + size, 0, minsize - size);
		memcpy(newmem, mem, size);
		delete []mem;
		mem = newmem;
		size = minsize;
	}
}

Mem::Mem(int sz)
{
	size = sz;
	mem = new byte[sz];
}

Mem::~Mem()
{
	delete []mem;
}

int 
Mem::msize()
{
	return size;
}

byte *
Mem::pointer(int minsize)
{
	ensureMinsize(minsize);
	return mem;
}

bool
Mem::moved(int sz)
{
	if (sz > size)
		return true;
	return false;
}

