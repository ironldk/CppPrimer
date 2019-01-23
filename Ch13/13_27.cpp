//Exercise 13.27: Define your own reference - counted version of HasPtr
#include "stdafx.h"
#include <string>
using std::string;
class HasPtr {
public:
	HasPtr(const string &s = string());
	HasPtr(const HasPtr &);
	HasPtr &operator=(const HasPtr &);
	~HasPtr();
private:
	string * ps;
	int i;
	size_t * use;
};
HasPtr::HasPtr(const string &s = string()):
	ps(new string(s)), i(0), use(new size_t(1)) { }
HasPtr::HasPtr(const HasPtr &orig):
	ps(orig.ps), i(orig.i), use(orig.use){ ++*use; }
HasPtr & HasPtr::operator=(const HasPtr &orig) {
	++*orig.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = orig.ps;
	i = orig.i;
	use = orig.use;
	return *this;
}
HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}

int main() {
	string a;
	return 0;
}