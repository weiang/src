/*************************************************************************
	> File Name: stash.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Wed, Jul 24, 2013  6:14:23 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
#include "stash.h"

using namespace std;

void
stash::init(int size)
{
	size = size;
	quantity = 0;
	next = 0;
	storage = NULL;
}

void 
stash::cleanup(void)
{
	if (quantity > 1)
		delete []storage;
	else if (quantity == 1)
		delete storage;
}

int  
stash::add(const void *element)
{
	if (next >= quantity)
		inflate(10);
	unsigned char *p = &storage[next * size];
	for (int i = 0; i < size; i ++) 
		*(p + i) = *((unsigned char *)element + i);
	next ++;
	return (next - 1);
}

void *
stash::fetch(int index)
{
	assert(index >= 0);
	if (index >= next)
		return NULL;
	return &storage[index * size];
}

void
stash::inflate(int increase)
{
	assert(increase > 0);
	int new_quantity = increase + quantity;
	unsigned char *new_storage = new unsigned char[new_quantity * size];
	for (int i = 0; i < next * size; i ++)
		new_storage[i] = storage[i];
	delete []storage;
	storage = new_storage;
	quantity = new_quantity;
}

int 
stash::count(void)
{
	return next;
}

