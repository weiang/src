#include "analysis.h"

bool compare_name(const core& a, const core& b)
{
	return a.name() < b.name();
}

bool compare_grade(const core& a, const core& b)
{
	return a.grade() < b.grade();
}

bool compare_name_ptr(const core* a, const core* b)
{
	return compare_name(*a, *b);
}
