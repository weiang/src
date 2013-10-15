/*************************************************************************
	> File Name: cat.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月27日 星期日 20时33分14秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ios>

using namespace std;

int main()
{
	ifstream infile("in");
	ofstream outfile("out");

	string s;

	while (getline(infile, s))
		outfile << s << endl;
	return 0;
}


