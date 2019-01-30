#pragma once
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
	friend bool operator==(const StrBlob &, const StrBlob &);
	friend bool operator!=(const StrBlob &, const StrBlob &);
	friend bool operator<(const StrBlob &, const StrBlob &);
	friend bool operator>(const StrBlob &, const StrBlob &);
	friend bool operator<=(const StrBlob &, const StrBlob &);
	friend bool operator>=(const StrBlob &, const StrBlob &);
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	StrBlob(const StrBlob &);
	StrBlob &operator=(const StrBlob &);
	string &operator[](size_t n) { 
		check(n, "out of range"); return data->at(n); }
	const string &operator[](size_t n) const { 
		check(n, "our of range"); return data->at(n); }
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	void push_back(const string &t) {data->push_back(t);}
	void push_back(const string &&t) {data->push_back(std::move(t));}
	void pop_back();
	// element access
	string& front();
	const string& front() const;
	string& back();
	const string& back() const;
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	string& deref() const;
	ConstStrBlobPtr& incr(); // prefix version
	string &operator[](size_t n) {
		auto p = check(n, "out of range"); return p->at(n);	}
	const string &operator[](size_t n) const {
		auto p = check(n, "our of range"); return p->at(n);	}
	ConstStrBlobPtr &operator++();
	ConstStrBlobPtr &operator--();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
	ConstStrBlobPtr &operator+=(size_t);
	ConstStrBlobPtr &operator-=(size_t);
	ConstStrBlobPtr &operator+(size_t)const;
	ConstStrBlobPtr &operator-(size_t)const;
private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<string>>
		check(size_t, const string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr; // current position within the array
};
bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);