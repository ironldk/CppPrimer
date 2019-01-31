//Exercise 10.9: Implement your own version of elimDups.Test your
//program by printing the vector after you read the input, after the call to
//unique, and after the call to erase.
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

void elimDups(vector<string> &svec){
	sort(svec.begin(), svec.end());
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
	auto end_unique = unique(svec.begin(), svec.end());
	for (auto i : svec)cout << "b " << i << " e";
	cout << svec.size() << endl;
	svec.erase(end_unique, svec.end());
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