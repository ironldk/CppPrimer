//Exercise 10.15: Write a lambda that captures an int from its enclosing
//function and takes an int parameter.The lambda should return the sum of
//the captured int and the int parameter.
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	int a = 1;
	auto su = [a](int b) -> int {return a + b; };
	cout << su(2) << endl;
	return 0;
}