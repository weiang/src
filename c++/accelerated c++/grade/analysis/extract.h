#ifndef	_EXTRACT_H_
#define	_EXTRACT_H_

#define	FAIL	60.0
#include "student_info.h"
#include "grade.h"
#include <vector>

typedef std::vector<student_info>	module;

module extract_fail(module&);

#endif

