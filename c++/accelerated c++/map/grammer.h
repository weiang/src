#ifndef _GRAMMER_H_
#define _GRAMMER_H_

#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef std::vector<std::string>	rule;
typedef std::vector<rule>	rule_collection;
typedef std::map<std::string, rule_collection>	grammer;

grammer
read_grammer(std::istream& in);

std::vector<std::string>
gen_sentence(const grammer&);

#endif


