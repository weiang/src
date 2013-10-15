/*************************************************************************
	> File Name: 7_2.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  2:43:12 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Message {
	public:
		Message(string str = "");
		void print();
		void print(string);

	private:
		string s;
};

Message::Message(string str)
{
	s = str;
}

void
Message::print()
{
	cout << s << endl;
}

void 
Message::print(string str)
{
	cout << str << s << endl;
}

int 
main(void)
{
	Message m("Hello, World!");
	m.print();
	m.print("Weiang");

	Message m2;
	m2.print();
	m2.print("Weiang");
	return 0;
}
