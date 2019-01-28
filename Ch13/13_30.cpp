//Exercise 13.30: Write and test a swap function for your valuelike version of
//HasPtr.Give your swap a print statement that notes when it is executed.
//Exercise 13.31: Give your class a < operator and define a vector of
//HasPtrs.Give that vector some elements and then sort the vector.
//Note when swap is called
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::cout;
using std::endl;
using std::string;
class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
	friend 	bool operator<(const HasPtr &, const HasPtr &);
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &origin){
		ps = new string(*origin.ps);
		i = origin.i;
	}
	HasPtr &operator=(const HasPtr &);
	~HasPtr() { delete ps; ps = nullptr; }
	void swap(HasPtr &);
private:
	string * ps;
	int i;
};

HasPtr & HasPtr::operator=(const HasPtr &origin) {
	auto new_ps = new string(*origin.ps);
	delete ps;
	ps = new_ps;
	i = origin.i;
	return *this;
}
void HasPtr::swap(HasPtr &rhs) {
	using std::swap;
	swap(this->ps, rhs.ps);
	swap(this->i, rhs.i);
	cout << "call void HasPtr::swap(HasPtr &rhs)" << endl;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
	cout << "call void swap(HasPtr &lhs, HasPtr &rhs)" << endl;
	lhs.swap(rhs);
}
bool operator<(const HasPtr & lhs, const HasPtr & rhs) {
	return *lhs.ps < *rhs.ps;
}
int main() {
	vector<HasPtr> hvec;
	hvec.reserve(3);
	hvec.push_back(string("c"));
	hvec.push_back(string("c"));
	hvec.push_back(string("a"));
	sort(hvec.begin(), hvec.end());
	return 0;
}