#include <iostream>
#include "Suite.h"
#include <cassert>
#include <cstddef>

using namespace std;
using namespace TestSuite;

long Suite::getNumPassed() const 
{
	long result = 0;
	for (int i = 0; i != tests.size(); i ++) 
		result += tests[i] -> getNumPassed();
	return result;
}

long Suite::getNumFailed() const
{
	long result = 0;
	for (int i = 0; i != tests.size(); i ++)
		result += tests[i] -> getNumFailed();
	return result;
}

void Suite::addTest(Test *t) throw(TestSuiteError)
{
	if (!t)
		throw TestSuiteError("Null test in Suite::addTest");
	else if (osptr && !(t -> getStream()))
		t ->  setStream(osptr);
	tests.push_back(t);
	t -> reset();
}

void Suite::addSuite(const Suite& s)
{
	for (size_t i = 0; i != s.tests.size(); i ++) {
		assert(s.tests[i]);
		addTest(s.tests[i]);
	}
}

void Suite::free()
{
	for (size_t i = 0; i != tests.size(); i ++) {
		delete tests[i];
		tests[i] = 0;
	}
}

void Suite::run()
{
	reset();
	for (size_t i = 0; i != tests.size(); i ++) {
		assert(tests[i]);
		tests[i] -> run();
	}
}

void Suite::reset()
{
	for (size_t i = 0; i != tests.size(); i ++) {
		assert(tests[i]);
		tests[i] -> reset();
	}
}

	
long Suite::report() const
{
	if (osptr) {
		long totFail = 0;
		*osptr << "Suite \"" << name 
				<< "\"\n=======";
		size_t i;
		for (i = 0; i < name.size(); i ++)
			*osptr << '=';
		*osptr << "=" << endl;
		for (i = 0; i < tests.size(); i ++) {
			assert(tests[i]);
			totFail += tests[i] -> report();
		}
		*osptr << "=======";
		for (i = 0; i < name.size(); i ++)
			*osptr << '=';
		*osptr << "=" << endl;
		return totFail;
	}
	else 
		return getNumFailed();
}



		

				
	



