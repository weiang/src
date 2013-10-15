#ifndef VECTOR_TEST_H_
#define VECTOR_TEST_H_

#include <iostream>
#include "Test.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::out_of_range;

class VectorTest : public TestSuite::Test {
	public:
		void run() 
		{
			for (int i = 0; i != 5; i ++) {
				intTest.push_back(i);
				test_(intTest[i] == i);
			}

			test_(intTest.front() == 0);
			test_(intTest.back() == 4);
			test_(intTest.size() == 5);
			intTest.pop_back();
			test_(intTest.size() == 3);	// Error 
			test_(intTest.back() == 3);
			test_(intTest.at(2) == 2);
			try {
				intTest.at(intTest.size());
				std::cout << "Hasn't caught except out_of_range" << endl;
			} catch (out_of_range&) {
				cout << "Has caught except out_of_range" << endl;
			}
		}

	private:
		vector<int> intTest;
};
	
#endif // VECTOR_TEST_H_
