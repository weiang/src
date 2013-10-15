/*************************************************************************
	> File Name: instrument.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Tue, Jul 30, 2013  8:46:20 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum note { middleC, Csharp, Cflat };

class instrument {
	public:
		void play(note) const { }
};

class wind : public instrument { };

void 
tune(instrument& i)
{
	i.play(middleC);
}

int 
main(void)
{
	wind w;
	tune(w);
	return 0;
}

