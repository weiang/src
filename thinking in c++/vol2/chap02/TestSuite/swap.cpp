/*************************************************************************
	> File Name: swap.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月08日 星期四 23时51分49秒
    > Describition: 
 ************************************************************************/

#include <iostream>

using namespace std;

class WidgetImp { 
	private:
		int i;
	public:
		WidgetImp(int i) : i(i) {}
		int read() const { return i; }
};

class Widget {
	private:
		WidgetImp *pImp;

	public:
		Widget(int i) 
		{
			pImp = new WidgetImp(i);
		}
		~Widget()
		{
			delete pImp;
		}
		int read() const { return pImp -> read(); }
		void swap(Widget& b);
};

void Widget::swap(Widget& b)
{
	using std::swap;
	swap(pImp, b.pImp);
}

namespace std {
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}

int main()
{
	Widget a(1), b(2);
	cout << "a = " << a.read() << endl;
	cout << "b = " << b.read() << endl;
	swap(a, b);
	cout << "a = " << a.read() << endl;
	cout << "b = " << b.read() << endl;
	return 0;
}


