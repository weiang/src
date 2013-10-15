#include "Handle.h"

class Cheshire {
	public:
		Cheshire(int a = 0);
		int read();
		void change(int);
		
	private:
		int i;
};

Cheshire::Cheshire(int a)
{
	i = a;
}

int
Cheshire::read()
{
	return i;
}

void 
Cheshire::change(int a)
{
	i = a;
}

Handle::Handle(int a)
{
	smile = new Cheshire(a);
}
	
Handle::~Handle()
{
	delete smile;
}

int
Handle::read()
{
	return smile -> read();
}

void 
Handle::change(int x)
{
	smile -> change(x);
}


