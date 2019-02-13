#include "stdafx.h"
#include "Sales_data.h"

struct Integral {
	// meaningless, it will be ignored by compiler.
	operator const int() { std::cout << "const int()" << std::endl; return 1; }
	// promising that this operator will not change the state of the obj
	operator int() const { std::cout << "int() const" << std::endl; return 0; }
};
int main() {
	Sales_data cp5("C++ Primer 5th", 4, 106.5);
	std::cout << cp5 << std::endl;
	std::cout << static_cast<std::string>(cp5) << std::endl;
	std::cout << static_cast<double>(cp5) << std::endl;
	std::cout << std::string(cp5) << std::endl;
	std::cout << double(cp5) << std::endl;
	Integral i;
	static_cast<const int>(i);
	return 0;
}