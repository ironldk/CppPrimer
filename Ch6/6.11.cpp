#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

void reset(int &obj) {
	obj = 0;
}

int main() {
	int toBeReset = 85;
	cout << "before reset: " << toBeReset << endl;
	reset(toBeReset);
	cout << "after reset: " << toBeReset << endl;
	return 0;
}