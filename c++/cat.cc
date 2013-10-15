/*************************************************************************
	> File Name: cat.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月27日 星期日 20时38分28秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	int	fail_cnt = 0;

	for (int i = 1; i < argc; i ++) {
		ifstream	in(argv[i]);
		if (in) {
			string s;
			while (getline(in, s))
				cout << s << endl;
		}
		else {
			cerr << "Cannot open file " << argv[i] << endl;
			++ fail_cnt;
		}
	}
	return fail_cnt;
}


