/*************************************************************************
	> File Name: hilo.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年08月03日 星期六 12时43分14秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Think of a number between 1 and 100" << endl
		 << "I will make a guess; "
		 << "tell me if I'm (H)igh or (L)ow" << endl;

	int low = 1, high = 100;
	bool guessed = false;
	while (!guessed) {
		if (low > high) {
			cout << "You cheated! I quit" << endl;
			return EXIT_FAILURE;
		}
		int guess = (low + high) / 2;
		cout << "My guess is " << guess << ".";
		cout << "(H)igh, (L)ow, or (E)qual? ";
		string response;
		cin >> response;
		switch (toupper(response[0])) {
			case 'H': 
				high = guess - 1;
				break;
			case 'L':
				low = guess + 1;
				break;
			case 'E':
				guessed = true;
				break;
			default:
				cout << "Invalid response" << endl;
				continue;
		}
	}
	cout << "I got it!" << endl;
	return EXIT_SUCCESS;
}

