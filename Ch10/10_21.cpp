//Exercise 10.21: Write a lambda that captures a local int variable and
//decrements that variable until it reaches 0. Once the variable is 0 additional
//calls should no longer decrement the variable.The lambda should return a
//bool that indicates whether the captured variable is 0.
#include"stdafx.h"
#include<iostream>
using std::cout;
using std::endl;

int main() {
	int a = 10;
	auto decrement_to_0 = [&a]()->bool {
		if (a == 0)
			return true;
		else {
			--a;
			return false;
		}
	};
	while (!decrement_to_0()) { cout << a; }
	return 0;
}