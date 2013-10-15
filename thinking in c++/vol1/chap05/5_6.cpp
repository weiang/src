/*************************************************************************
	> File Name: 5_6.cpp
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  4:57:14 PM
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hen;
class Nest;
class Egg;

class Hen {
	public:
		class Nest {
			public:
				class Egg {
					private:
						int egg;
				
					public:
						void display()
						{
							cout << "In Egg: " << egg << endl;
						}
						friend class Nest; 
				};

				void display(Egg *e)
				{
					cout << "In Nest: egg =  " << e -> egg << endl;
				}

				friend class Hen;

			private:
				int nest;	
		};

		void display(Nest *n)
		{
			cout << "In Hen: nest = " << n -> nest << endl;
		}
};

int 
main(void)
{
	Hen a;
	Hen::Nest b;
	Hen::Nest::Egg c;

	a.display(&b);
	b.display(&c);
	c.display();

	return 0;

}

