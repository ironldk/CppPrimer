#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::sort;
using std::vector;
class Foo {
public:
	Foo() = default;
	Foo(const Foo &f) { cout << "Foo(const Foo &f)" << endl; data = f.data; }
	Foo & operator=(const Foo&) &;
	Foo sorted() && ; // may run on modifiable rvalues
	Foo sorted() const &; // may run on any kind of Foo
						  // other members of Foo
private:
	vector<int> data;
};
Foo &Foo::operator=(const Foo &rhs) &
{
	cout << "Foo &operator=(const Foo &) &" << endl;
	// do whatever is needed to assign rhs to this object
	return *this;
}
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() && {
	cout << "Foo sorted() &&" << endl;
	sort(data.begin(), data.end());
	return *this;
}
// this object is either const or it is an lvalue; either way we can't sort in place
Foo Foo::sorted() const & {
	cout << "Foo sorted() const &" << endl;
	//Foo ret(*this); // make a copy
	//sort(ret.data.begin(), ret.data.end()); // sort the copy
	//return ret; // return the copy
	return Foo(*this).sorted();
}

int main() {
	/*Foo f,g;
	g = f.sorted();*/
	Foo().sorted(); // call "&&"
	Foo f;
	f.sorted(); // call "const &"
	return 0;
}