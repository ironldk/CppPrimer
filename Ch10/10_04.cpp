//Exercise 10.4: Assuming v is a vector<double>, what, if anything, is
//wrong with calling accumulate(v.cbegin(), v.cend(), 0) ?
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;
using std::cout;
using std::endl;
using std::accumulate;

int main() {
	vector<double> v = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5 };
	int sum = 0;
	sum = accumulate(v.cbegin(), v.cend(), 0);//loss of accuracy
	cout << sum << endl;
	return 0;
}