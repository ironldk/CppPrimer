//Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
//of integers from the standard input, sort them, and then write them back to
//the standard output
//Exercise 10.31: Update the program from the previous exercise so that it
//prints only the unique elements.Your program should use unqiue_copy(¡ì
//10.4.1, p. 403)
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
//#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::back_inserter;
using std::copy;
using std::unique_copy;
using std::sort;

int main() {
	istream_iterator<int> iter_int(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec;
	copy(iter_int, eof, back_inserter(ivec));
	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), out);
	return 0;
}