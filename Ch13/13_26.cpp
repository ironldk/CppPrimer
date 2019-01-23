//Exercise 13.25: Assume we want to define a version of StrBlob that acts
//like a value.Also assume that we want to continue to use a shared_ptr so
//that our StrBlobPtr class can still use a weak_ptr to the vector.Your
//revised class will need a copy constructor and copy - assignment operator but
//will not need a destructor.Explain what the copy constructor and copyassignment
//operators must do.Explain why the class does not need a
//destructor.
//Exercise 13.26 : Write your own version of the StrBlob class described in
//the previous exercise.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

class ConstStrBlobPtr;
class StrBlob {
	friend class ConstStrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	StrBlob(const StrBlob &);
	StrBlob &operator=(const StrBlob &);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	void push_back(const string &t) {
		data->push_back(t);
	}
	void pop_back();
	// element access
	string& front();
	const string& front() const;
	string& back();
	const string& back() const;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	string& deref() const;
	ConstStrBlobPtr& incr(); // prefix version
private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<string>>
		check(size_t, const string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr; // current position within the array
};
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }
StrBlob::StrBlob(const StrBlob &origin) {
	data = make_shared<vector<string>>(*origin.data);
}
StrBlob &StrBlob::operator=(const StrBlob &rhs) {
	data = make_shared<vector<string>>(*rhs.data);
	return *this;
}
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}
string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}
const string& StrBlob::front() const
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	cout << "const";
	return data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	cout << "const";
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}
shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, const string &msg)
const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}
string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr]; // (*p) is the vector to which this object points
}
// prefix: return a reference to the incremented object
ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	++curr; // advance the current state
	return *this;
}
int main() {
	ifstream inputFile("in.txt");
	StrBlob text;
	string line;
	while (getline(inputFile, line)) {
		text.push_back(line);
	}
	for (ConstStrBlobPtr wp(text); wp.deref() != text.end().deref(); wp.incr()) {
		cout << wp.deref() << endl;
	}
	return 0;
}