#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

void swap(int &l, int &r) {
	auto temp = l;
	l = r;
	r = temp;
}

int main() {
	int first = 16, second = 18;
	cout << "before swap: " << "\t" << first << "\t" << second << endl;
	swap(first, second);
	cout << "after swap: " << "\t" << first << "\t" << second << endl;
	return 0;
}