#pragma once
#include <memory>
#include <iostream>
using std::ostream;
using std::pair;
using std::allocator;
class String {
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	friend ostream &operator<<(ostream &, const String &);
public:
	String():String(""){}
	String(const char *);
	String(const String &);
	String(String &&)noexcept;
	String &operator=(const String &);
	String &operator=(String &&)noexcept;
	char &operator[](size_t n){ return elements[n]; }
	const char &operator[](size_t n) const{ return elements[n]; }
	~String() { free(); }
	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }
private:
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initialize(const char*, const char*);
	void free();
private:
	char *elements;
	char *end;
	allocator<char> alloc;
};
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator>(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);
ostream &operator<<(ostream &, const String &);