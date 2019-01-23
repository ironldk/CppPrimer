//Exercise 10.33: Write a program that takes the names of an input file and
//two output files.The input file should hold integers.Using an
//istream_iterator read the input file.Using ostream_iterators, write
//the odd numbers into the first output file.Each value should be followed by a
//space.Write the even numbers into the second file.Each of these values
//should be placed on a separate line.
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <functional>
//#include <numeric>
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;
using std::back_inserter;
using std::copy;
using std::partition;

int main()
{
	ifstream in("input_file");
	ofstream odd("odd_file"), even("even_file");
	istream_iterator<int> iter_int(in), eof;
	ostream_iterator<int> iter_odd(odd, " "), iter_even(even, "\n");
	vector<int> ivec, odd, even;
	copy(iter_int, eof, back_inserter(ivec));
	auto even_beg = partition(ivec.begin(), ivec.end(), [](const int &a) { return bool(a % 2); });
	copy(ivec.begin(), even_beg, iter_odd);
	copy(even_beg, ivec.end(), iter_even);
	return 0;
}