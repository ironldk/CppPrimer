#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void swap(/*const*/ int *&left, /*const*/ int *&right) {
	auto temp = left;
	left = right;
	right = temp;
}

int main() {
	int first, second;
	cout << "input two ints:";
	cin >> first >> second;
	auto l = &first, r = &second;
	swap(l, r);
	cout << *l << *r << endl;
	return 0;
}