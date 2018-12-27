//Exercise 10.13: The library defines an algorithm named partition that
//takes a predicate and partitions the container so that values for which the
//predicate is true appear in the first part and those for which the predicate is
//false appear in the second part.The algorithm returns an iterator just past
//the last element for which the predicate returned true.Write a function that
//takes a string and returns a bool indicating whether the string has five
//characters or more.Use that function to partition words.Print the elements
//that have five or more characters.
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

bool longer_than_5(const string &a) {
	return a.size() > 5;
}

int main() {
	vector<string> vec;
	string s;
	while (cin >> s)vec.push_back(s);
	partition(vec.begin(), vec.end(), longer_than_5);
	for (auto i : vec)cout << "b " << i << " e";
	cout << vec.size() << endl;
	return 0;
}