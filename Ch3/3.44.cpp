#include "stdafx.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	typedef int (&rArr4Ints)[4];
	typedef int &rInt;
	typedef int (*pArr4Ints)[4];
	typedef int *pInt;
	int ia[3][4];
	size_t cnt = 0;
	for (rArr4Ints row : ia) {
		for (rInt col : row) {
			col = cnt;
			cnt++;
		}
	}

	for (rArr4Ints row : ia) {
		for (int col : row) {
			cout << col << ' ';
		}
		cout << endl;
	}

	for (size_t i = 0; i != 3; i++) {
		for (size_t j = 0; j != 4; j++) {
			cout << ia[i][j] << ' ';
		}
		cout << endl;
	}

	for (pArr4Ints p = ia; p != ia + 3; ++p) {
		for (pInt q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	return 0;
}