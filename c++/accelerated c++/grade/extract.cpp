#include "extract.h"
#include "grade.h"

using namespace std;

module extract_fail(module& s)
{
	module	fail;

	for(module::iterator	i = s.begin(); i != s.end(); ) {
		double result = grade(*i);
		if (result < FAIL) {
			fail.push_back(*i);
			i = s.erase(i);
		}
		else 
			i ++;
	}
	return fail;
}


