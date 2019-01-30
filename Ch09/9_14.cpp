#include "stdafx.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>
using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	list<const char*> pstring{"Hello", " ", "World", "!"};
	vector<string> vstring;
	vstring.assign(pstring.cbegin(), pstring.cend());
	for (const auto &s : vstring) cout << s << endl;
	return 0;
}