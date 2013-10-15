/*************************************************************************
	> File Name: framis.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 01时22分35秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstddef>
#include <fstream>
#include <new>

using namespace std;

class Framis {
	public:
		enum { psize = 100 };
		Framis() { cout << "Framis() " << endl; }
		~Framis() { cout << "~Framis() " << endl; }
		void *operator new(size_t) throw(bad_alloc);
		void *operator new[](size_t) throw(bad_alloc);
		void operator delete(void *);
		void operator delete[](void *);

	private:
		enum { size = 10 };
		char c[size];
		static unsigned char pool[];
		static bool alloc_map[];
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = { false };

void* Framis::operator new(size_t) throw(bad_alloc)
{
	for (int i = 0; i < psize; i ++) {
		if (!alloc_map[i]) {
			cout << "Using block " << i << endl;
			alloc_map[i] = true;
			return pool + sizeof(Framis) * i;
		}
	}
	cout << "Out of memory" << endl;
	throw bad_alloc();
}

void Framis::operator delete(void *p)
{
	if (!p)
		return;
	unsigned long block = (unsigned long)p - (unsigned long)pool;
	block /= sizeof(Framis);
	cout << "Freeing block " << block << endl;
	alloc_map[block] = false;
}

int main()
{
	Framis *f[Framis::psize];
	try {
		for (int i = 0; i < Framis::psize; i ++)
			f[i] = new Framis;
		new Framis;
	} catch (bad_alloc) {
		cerr << "Out of memory" << endl;
	}

	delete f[10];
	f[10] = 0;
	Framis *x = new Framis;
	delete x;
	for (int i = 0; i < Framis::psize; i ++)
		delete f[i];

	cout << endl << endl << endl;

	Framis *f2 = new Framis[10];
	delete[] f2;

	return 0;
}

