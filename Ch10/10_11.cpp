//Exercise 10.11: Write a program that uses stable_sort and isShorter
//to sort a vector passed to your version of elimDups.Print the vector to
//verify that your program is correct.
//input: the quick red fox jumps over the slow red turtle
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

bool isShorter(const string &a, const string &b) {
	return a.size() < b.size();
}

void elimDups(vector<string> &svec) {
	sort(svec.begin(), svec.end());
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
	auto end_unique = unique(svec.begin(), svec.end());
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
	svec.erase(end_unique, svec.end());
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
}

int main() {
	vector<string> vec;
	string s;
	while (cin >> s)vec.push_back(s);
	for (auto i : vec)cout << "b " << i << " e";
	cout << vec.size() << endl;
	elimDups(vec);
	return 0;
}