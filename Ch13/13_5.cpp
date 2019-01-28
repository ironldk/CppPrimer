//Exercise 13.5: Given the following sketch of a class, write a copy
//constructor that copies all the members.Your constructor should dynamically
//allocate a new string(¡ì 12.1.2, p. 458) and copy the object to which ps
//points, rather than copying ps itself
#include "stdafx.h"
#include <string>
using std::string;
class HasPtr {
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &);
	HasPtr &operator=(const HasPtr &);
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &origin) {
	i = origin.i;
	ps = new string(*origin.ps);
}

HasPtr & HasPtr::operator=(const HasPtr &origin) {
	delete ps;
	ps = new string(*origin.ps);
	i = origin.i;
	return *this;
}

int main() {
	string a;
	return 0;
}