/*************************************************************************
	> File Name: 7_1.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Sat, Jul 27, 2013  2:25:16 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Text {
	public:
		Text();
		Text(string);
		const string& contents();

	private:
		string text;
};

Text::Text()
{
	text = "";
}

Text::Text(string s)
{
	ifstream in(s.c_str());

	string str;
	while (getline(in, str)) {
		str += '\n';
		text += str;
	}
}

const string&
Text::contents()
{
	return text;
}

int 
main(void)
{
	string t;
	cin >> t;
	Text a(t);
	cout << a.contents();
	return 0;
}

