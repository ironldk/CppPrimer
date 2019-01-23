//Exercise 13.14: Assume that numbered is a class with a default constructor
//that generates a unique serial number for each object, which is stored in a
//data member named mysn.Assuming numbered uses the synthesized copy control members
//and given the following function :
//what output does the following code produce ?
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class numbered {
public:
	numbered() { mysn = ++unique; }
	int mysn;
	static int unique;
};
int numbered::unique = 10;
void f(numbered s) { cout << s.mysn << endl; }
int main() {
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
}