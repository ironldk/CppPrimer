//Exercise 10.1: The algorithm header defines a function named count
//that, like find, takes a pair of iterators and a value.count returns a count
//of how often that value appears.Read a sequence of ints into a vector
//and print the count of how many elements have a given value
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::count;

int main() {
	vector<int> ivec;
	int i, wanted;
	cout << "Input vector of ints: ";
	while (cin >> i) {
		ivec.push_back(i);
	}
	cin.clear();
	cin.sync();
	cout << "Input value wanted to be counted: ";
	cin >> wanted;
	auto cnt = count(ivec.cbegin(), ivec.cend(), wanted);
	cout << "value " << wanted << " appeared " << cnt << " times." << endl;
	return 0;
}