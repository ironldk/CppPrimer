//Exercise 10.6: Using fill_n, write a program to set a sequence of int
//values to 0.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::equal;

int main() {
	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto i : ivec)cout << i << endl;
	fill_n(ivec.begin(), ivec.size(), 0);
	for(auto i : ivec)cout << i << endl;
	return 0;
}