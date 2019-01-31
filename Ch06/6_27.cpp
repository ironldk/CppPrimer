#include "stdafx.h"
#include <iostream>
#include <initializer_list>
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

int	sum(initializer_list<int> il) {
	int s = 0;
	for (auto i = il.begin(); i != il.end(); i++) {
		s += *i;
	}
	return s;
}

int main() {
	int s;
	s = sum({1 , 2 , 3 , 4 , 5});
	cout << s << endl;
	return 0;
}