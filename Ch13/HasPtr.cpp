#include "HasPtr.h"
void swap(HasPtr &lhs, HasPtr &rhs) {
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
	std::swap(lhs.use, rhs.use);
}
HasPtr::HasPtr(const string &s = string()) :
	ps(new string(s)), i(0), use(new size_t(1)) { }
HasPtr::HasPtr(const HasPtr &orig) :
	ps(orig.ps), i(orig.i), use(orig.use) {
	++*use;
}
HasPtr::HasPtr(HasPtr &&orig)noexcept:
	ps(orig.ps), i(orig.i), use(orig.use) {
	orig.ps = nullptr;
	orig.use = nullptr;
}
//HasPtr &HasPtr::operator=(HasPtr rhs) {
//	swap(*this, rhs);
//	return *this;
//}
HasPtr &HasPtr::operator=(const HasPtr &orig) {
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
HasPtr &HasPtr::operator=(HasPtr &&orig)noexcept{
	if (this != &orig) {
		ps = orig.ps;
		i = orig.i;
		use = orig.use;
		orig.ps = nullptr;
		orig.use = nullptr;
	}
	return *this;
}
HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}