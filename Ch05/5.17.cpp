#include "stdafx.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> one = { 0, 1, 1, 2 }, two = { 0, 1, 1, 2, 3, 5, 8 };
	vector<int>::size_type length = (one.size() > two.size()) ? two.size() : one.size();
	for (vector<int>::size_type iter = 0; iter != length; iter++) {
		if (one[iter] != two[iter]) {
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
  	return 0;
}