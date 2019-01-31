#include "stdafx.h"
#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	int a, b;
	cout << "input two numbers: ";
	while (cin >> a >> b) {
		try {
			if (b == 0) throw runtime_error("divisor is 0");
			cout << static_cast<double>(a) / b << endl;
		}
		catch (runtime_error err){
			cout << err.what() << endl;
		}
		cout << "input two numbers: ";
	}
	return 0;
}