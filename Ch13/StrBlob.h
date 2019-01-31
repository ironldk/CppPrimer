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
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
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
	string& back();
	const string& front() const;
	const string& back() const;
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
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
class StrBlobPtr {
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(const StrBlob &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	string& deref() const;
	StrBlobPtr& incr(); // prefix version
	string &operator[](size_t n) {
		auto p = check(n, "out of range"); return p->at(n);
	}
	const string &operator[](size_t n) const {
		auto p = check(n, "our of range"); return p->at(n);
	}
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	StrBlobPtr &operator+=(size_t);
	StrBlobPtr &operator-=(size_t);
	StrBlobPtr &operator+(size_t)const;
	StrBlobPtr &operator-(size_t)const;
	string &operator*();
	string *operator->();
private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<string>>
		check(size_t, const string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr; // current position within the array
};
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr != rhs.curr;
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr < rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr > rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr <= rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr >= rhs.curr;
}


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
	const string &operator*();
	const string *operator->();
private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<string>>
		check(size_t, const string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr; // current position within the array
};
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr != rhs.curr;
}
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr < rhs.curr;
}
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr > rhs.curr;
}
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr <= rhs.curr;
}
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return lhs.curr >= rhs.curr;
}