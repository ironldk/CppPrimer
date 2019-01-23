//Exercise 12.19: Define your own version of StrBlobPtr and update your
//StrBlob class with the appropriate friend declaration and begin and end
//members
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
using std::string;
using std::vector;
using std::shared_ptr;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::cout;
using std::endl;
using std::cin;

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
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
	StrBlobPtr begin() { return StrBlobPtr(*this); }
	StrBlobPtr end(){
		auto ret = StrBlobPtr(*this, data->size());
		return ret;
	}
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incr(); // prefix version
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; // current position within the array
};
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }
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
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg)
const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}
std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr]; // (*p) is the vector to which this object points
}
// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	++curr; // advance the current state
	return *this;
}
int main() {
	StrBlob a = { "a", "b", "c" };
	const StrBlob b = { "a", "b", "c", "d" };
	cout << a.front() << " " << a.back() << endl;
	cout << b.front() << " " << b.back() << endl;
	return 0;
}