//Exercise 11.3: Write your own version of the word - counting program.
//Input: Although most programmers are familiar with data structures such as vectors and
//lists, many have never used an associative data structure.Before we look at the
//details of how the library supports these types, it will be helpful to start with examples
//of how we can use these containers
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::cin;
int main() {
	map<string, size_t> count;
	string word;
	while (cin >> word) {
		++count[word];
	}
	for (const auto &w : count) {
		cout << w.first << " occurs " << w.second
			 << ((w.second > 1) ? " times." : " time.") << endl;
	}
	return 0;
}