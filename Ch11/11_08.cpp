//Exercise 11.8: Write a program that stores the excluded words in a vector
//instead of in a set.What are the advantages to using a set ?
//Input: Although most programmers are familiar with data structures such as vectors and
//lists, many have never used an associative data structure.Before we look at the
//details of how the library supports these types, it will be helpful to start with examples
//of how we can use these containers
#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using std::find;
using std::string;
using std::map;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
int main() {
	map<string, size_t> count;
	string word;
	vector<string> exclude = { "the", "but", "and", "or", "an", "a", "The", "But", "And", "Or", "An", "A" };
	while (cin >> word && find(exclude.begin(), exclude.end(), word) == exclude.end()) {
		++count[word];
	}
	for (const auto &w : count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times." : " time.") << endl;
	}
	return 0;
}