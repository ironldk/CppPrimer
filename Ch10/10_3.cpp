//Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
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
	vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;
	return 0;
}