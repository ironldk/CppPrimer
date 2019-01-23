//Exercise 13.14: Assume that numbered is a class with a default constructor
//that generates a unique serial number for each object, which is stored in a
//data member named mysn.Assuming numbered uses the synthesized copy control members
//and given the following function :
//what output does the following code produce ?
//Exercise 13.15: Assume numbered has a copy constructor that generates a
//new serial number.Does that change the output of the calls in the previous
//exercise ? If so, why ? What output gets generated ?
//Exercise 13.16: What if the parameter in f were const numbered& ?
//Does that change the output ? If so, why ? What output gets generated ?
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class numbered {
public:
	numbered() { mysn = ++unique; }
	numbered(numbered &origin) { mysn = ++unique; }
	int mysn;
	static int unique;
};
int numbered::unique = 10;
void f(const numbered &s) { cout << s.mysn << endl; }
int main() {
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	return 0;
}