#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;

int seq(void) {
	static int i = 0;
	return i++;
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << seq() << endl;
	}
	return 0;
}