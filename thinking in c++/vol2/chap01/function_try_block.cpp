/*************************************************************************
	> File Name: function_try_block.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月02日 星期五 02时22分22秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() try 
{
	throw "main";
} catch (const char *msg) {
	cout << msg << endl;
	return 1;
}
