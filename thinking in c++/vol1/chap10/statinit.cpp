#include <iostream>

using namespace std;

int x = 100;

class withStatic {
		static int x;
		static int y;
	public:
		void print() const
		{
			cout << "withStatic::x = " << x << endl;
			cout << "withStatic::y = " << y << endl;
		}
};

int withStatic::x = 1;
int withStatic::y = ::x + 1;

int 
main(void)
{
	withStatic ws;
	ws.print();
	return 0;
}



