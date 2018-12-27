//Exercise 10.14: Write a lambda that takes two ints and returns their sum
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	auto su = [](int a, int b) -> int {return a + b; };
	cout << su(1,2) << endl;
	return 0;
}