#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int theLarger(const int i, const int *const pi) {
	return i > *pi ? i : *pi;
}

int main() {
	int first, second;
	cout << "input two ints:";
	cin >> first >> second;
	cout << theLarger(first, &second) << " is larger." << endl;
	return 0;
}