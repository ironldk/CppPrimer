//Exercise 11.12: Write a program to read a sequence of strings and ints,
//storing each into a pair.Store the pairs in a vector.
//Exercise 11.13: There are at least three ways to create the pairs in the
//program for the previous exercise.Write three versions of that program,
//creating the pairs in each way.Explain which form you think is easiest to
//write and understand, and why.
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
		//p = { p1, p2 };
		//p = make_pair(p1, p2);
		p = pair<string, int>(p1, p2);
		pvec.push_back(p);
	}
	for (const auto &w : pvec) {
		cout << w.first << " " << w.second << endl;
	}
	return 0;
}