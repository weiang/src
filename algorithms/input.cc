/*************************************************************************
	> File Name: input.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月19日 星期四 19时56分56秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

void input(const char *filename, int limit, int num)
{
	ofstream of(filename);

	of << num << endl;

	for (int i = 0; i != num; i ++) {
		int tmp = rand() % limit;
		of << tmp << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4) {
		cerr << "Usage: " << argv[0] << " <limit> <array size> <filename>" << endl;
		return -1;
	}

	int limit = atoi(argv[1]);
	int cnt = atoi(argv[2]);
	input(argv[3], limit, cnt);
	return 0;
}



