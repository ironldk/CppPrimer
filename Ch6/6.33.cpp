#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
// using std::initializer_list;
// using std::string;

void printVector(vector<int> vi, vector<int>iterator end)
{
	if (end != 0) {
		printVector(vi, end - 1);
		std::cout << vi[end] << endl;
	}
	else {
		std::cout << vi[0] << endl;
	}
}

int main() {
	vector<int> i = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVector(i, 9);
	return 0;
}