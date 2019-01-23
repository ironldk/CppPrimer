//Exercise 11.12: Write a program to read a sequence of strings and ints,
//storing each into a pair.Store the pairs in a vector.
#include "stdafx.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using std::string;
using std::pair;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
int main() {
	vector<pair<string, int>> pvec;
	pair<string, int> p;
	string p1;
	int p2;
	while (cin >> p1 >> p2) {
		p = { p1, p2 };
		pvec.push_back(p);
	}
	for (const auto &w : pvec) {
		cout << w.first << " " << w.second << endl;
	}
	return 0;
}