//Exercise 10.29: Write a program using stream iterators to read a text file
//into a vector of strings.
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::copy;

int main() {
	ifstream i("afile");
	istream_iterator<string> iter_string(i), eof;
	ostream_iterator<string> out(cout);
	vector<string> svec;
	while (iter_string != eof) {
		svec.push_back(*iter_string++);
	}
	copy(svec.begin(), svec.end(), out);
	return 0;
}