/*************************************************************************
	> File Name: grammer.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年01月23日 星期三 21时57分23秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "grammer.h"
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include "split.h"

using namespace std;

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Arguement to nrand is out of range");

	const int bucket_size = RAND_MAX / n;

	int r;
	do {
		r = rand() / bucket_size;
	} while (r >= n);
	
	return r;
}

grammer
read_grammer(istream& in)
{
	string	s;
	grammer	ret;

	while (getline(in, s)) {
		vector<string> word = split(s);

		if (!word.empty()) {
			ret[word[0]].push_back(rule(word.begin() + 1, word.end()));
		}
	}
	return ret;
}

void gen_aux(const grammer& g, const string& s, vector<string>& ret)
{
	if (!bracketed(s)) {
		ret.push_back(s);
	}
	else {
		grammer::const_iterator	it = g.find(s);
		if (it == g.end())
			throw logic_error("empty rule");
		
		const rule_collection& se = it -> second;
		const rule& r = se[nrand(se.size())];

		for (rule::const_iterator i = r.begin(); i != r.end(); i ++)
			gen_aux(g, *i, ret);
	}
}


vector<string>
gen_sentence(const grammer& g)
{
	vector<string>	ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
