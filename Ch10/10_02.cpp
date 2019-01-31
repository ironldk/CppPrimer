//Exercise 10.1: The algorithm header defines a function named count
//that, like find, takes a pair of iterators and a value.count returns a count
//of how often that value appears.Read a sequence of ints into a vector
//and print the count of how many elements have a given value.
//Exercise 10.2 : Repeat the previous program, but read values into a list of
//strings.
#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::count;

int main() {
	list <string> ilst;
	string i, wanted;
	cout << "Input list of strings: ";
	while (cin >> i) {
		ilst.push_back(i);
	}
	cin.clear();
	cin.sync();
	cout << "Input string wanted to be counted: ";
	cin >> wanted;
	auto cnt = count(ilst.cbegin(), ilst.cend(), wanted);
	cout << "string " << wanted << " appeared " << cnt << " times." << endl;
	return 0;
}