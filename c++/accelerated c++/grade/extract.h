#ifndef	_EXTRACT_H_
#define	_EXTRACT_H_

#define	FAIL	60.0
#include "student_info.h"
#include <list>

typedef std::list<student_info>	module;

module extract_fail(module&);

#endif

