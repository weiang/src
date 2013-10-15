/*************************************************************************
	> File Name: NestFriend.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  8:48:13 AM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int sz = 20;

struct holder {
	private:
		int a[sz];
	public:
		struct pointer {
			private:
				holder *h;
				int *p;
			public:
				void init(holder *);
				void next();
				void previous();
				void top();
				void end();
				int read();
				void set(int);
		};
		void init();
		friend void pointer::init(holder *);
};

void 
holder::init()
{
	memset(a, 0, sizeof(int) * sz);
}

void
holder::pointer::init(holder *rv)
{
	h = rv;
	p = rv -> a;
}

void 
holder::pointer::next()
{
	if (p < &(h -> a[sz - 1])) p ++;
}

void
holder::pointer::previous()
{
	if (p > h -> a) p --;
}

void 
holder::pointer::top()
{
	p = h -> a;
}

void
holder::pointer::end()
{
	p = &(h -> a[sz -1]);
}

int 
holder::pointer::read()
{
	return *p;
}

void
holder::pointer::set(int i)
{
	*p = i;
}


int 
main()
{
	holder h;
	holder::pointer hp, hp2;
	int i;

	h.init();
	hp.init(&h);
	hp2.init(&h);
	for (i = 0;i < sz; i ++) {
		hp.set(i);
		hp.next();
	}

	hp.top();
	hp2.end();
	for(i = 0; i < sz; i ++) {
		cout << "hp = " << hp.read()
			<< ", hp2 = " << hp2.read() << endl;
		hp.next();
		hp2.previous();
	}
	return 0;
}


