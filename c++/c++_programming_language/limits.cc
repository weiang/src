/*************************************************************************
	> File Name: limits.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年02月22日 星期五 09时54分50秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <limits>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	cout << "Largest float == " << numeric_limits<float>::max()
		 << ", Char is signed == " << numeric_limits<char>::is_signed << endl; 
	char max_char = numeric_limits<char>::max();
	printf("Largest char == %c", max_char);
	printf("Smallest char == %c\n", numeric_limits<char>::min());
	cout << "Largest short, int, long, double, long double, unsigned == "
		 << numeric_limits<short>::max() << ' '
		 << numeric_limits<int>::max() << ' '
		 << numeric_limits<long>::max() << ' '
		 << numeric_limits<double>::max() << ' '
		 << numeric_limits<long double>::max() << ' '
		 << numeric_limits<unsigned>::max() << endl;

	return 0;
}
