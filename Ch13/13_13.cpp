#include "stdafx.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
//Exercise 13.13: A good way to understand copy - control members and
//constructors is to define a simple class with these members in which each
//member prints its name :
//Add the copy - assignment operator and destructor to X and write a program using
//X objects in various ways : Pass them as nonreference and reference parameters;
//dynamically allocate them; put them in containers; and so forth.Study the output
//until you are certain you understand when and why each copy - control member is
//used.As you read the output, remember that the compiler can omit calls to the
//copy constructor.
struct X {
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this; }
	~X(){ cout << "~X()" << endl; }
};
int main() {
	X x1, &x2 = x1, *px = new X; cout << "1" << endl;
	X x3 = X(x1), x4 = X(x2); cout << "2" << endl;
	vector<X> Xvec; cout << "3" << endl;
	Xvec.push_back(x1); cout << "4" << endl;
	Xvec.push_back(x1); cout << "5" << endl;
	return 0;
}
//void f(const X& rx, X x)
//{
//	std::vector<X> vec;
//	//vec.reserve(2);
//	vec.push_back(rx);
//	vec.push_back(x);
//}
//int main()
//{
//	X* px = new X;
//	f(*px, *px);
//	delete px;
//
//	return 0;
//}