/*************************************************************************
	> File Name: test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年06月26日 星期三 16时47分32秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int
main(void)
{
	const std::string hello = "Hello";
//	const std::string message = hello + ",world" + "!";
	const std::string exclam = " ! ";
	const std::string message2 = "Hello" + ",world";

//	std::cout << message << std::endl;
	std::cout << message2 << std::endl;
	return 0;
}
