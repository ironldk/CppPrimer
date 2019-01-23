//Exercise 10.32: Rewrite the bookstore problem from ¡ì 1.6 (p. 24) using a
//vector to hold the transactions and various algorithms to do the processing.
//Use sort with your compareIsbn function from ¡ì 10.3.1 (p. 387) to
//arrange the transactions in order, and then use find and accumulate to
//do the sum
#include "stdafx.h"
#include "Sales_item.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <numeric>
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
using std::find_if;
using std::accumulate;

int main()
{
	istream_iterator<Sales_item> iter_int(cin), eof;
	ostream_iterator<Sales_item> out(cout, "\n");
	vector<Sales_item> vec;
	vector<Sales_item> sum;
	copy(iter_int, eof, back_inserter(vec));
	sort(vec.begin(), vec.end(), [](const Sales_item &lhs, const Sales_item &rhs){ return lhs.isbn < rhs.isbn; });
	for (auto beg = vec.begin(), end = beg; end != vec.end(); beg = end) {
		end = find_if(beg, vec.end(), [beg](const Sales_item &current) { return beg -> isbn != current.isbn; });
		accumulate(beg, end, back_inserter(sum));
	}
	return 0;
}