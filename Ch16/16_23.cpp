#include <iostream>
using std::cout;
using std::endl;
int main() {
	int a = 3;
	const int b = 2;
	auto c = a * b;
	const int *p = &c;
	return 0;
}