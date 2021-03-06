#include "stdafx.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int ia[3][4];
    size_t cnt = 0;
    for (auto &row : ia) {
        for (auto &col : row) {
            col = cnt;
            cnt++;
        }
    }

    for (int (&row)[4] : ia) {
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

    for (int (*p)[4] = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
	return 0;
}
