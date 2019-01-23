//Exercise 10.34: Use reverse_iterators to print a vector in reverse
//order.
//Exercise 10.35: Now print the elements in reverse order using ordinary
//iterators.
//Exercise 10.36: Use find to find the last element in a list of ints with
//value 0.
//Exercise 10.37 : Given a vector that has ten elements, copy the elements
//from positions 3 through 7 in reverse order to a list.
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

int main()
{
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> ilst1(ivec.begin(), ivec.end()), ilst2;
	copy(ivec.crbegin(), ivec.crend(), out);
	copy(ivec.cbegin(), ivec.cend(), out);
	auto iter = find(ilst1.crbegin(), ilst1.crend(), 0);
	cout << *iter << endl;
	copy(ivec.crbegin() + 3, ivec.crbegin()+8, back_inserter(ilst2));
	copy(ilst2.cbegin(), ilst2.cend(), out);
	return 0;
}