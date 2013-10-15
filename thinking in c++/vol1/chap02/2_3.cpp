/*************************************************************************
	> File Name: 2_3.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Mon, Jul 22, 2013  3:21:34 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <fstream>

/*
 * Count the number of words in a file 
 */
int main(void)
{
	string file;
	cin >> file;
	ifstream in(file.c_str());

	int cnt = 0;
	string str;
	while (getline(in, str)) {
		int i = 0;
		/* Ignore whitespace at the begin of a line */
		while (i != str.size()) {
			while (str[i] == ' ' && i != str.size())
				i ++;
			if (i != str.size())
				cnt ++;
			while (str[i] != ' ' && i != str.size()) 
				i ++;
		}
	}
	cout << file << " has " << cnt << " words!" << endl;
	return 0;
}
