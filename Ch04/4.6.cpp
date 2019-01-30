#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main() {
	int a;
	while (cin >> a) {
		bool isEven = a % 2 ? false : true;
		cout << (isEven ? "even" : "odd") << endl;
	}
	return 0;
}