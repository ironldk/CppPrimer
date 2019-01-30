#pragma once
#include "stdafx.h"
#include "String.h"
#include <iostream>
#include <algorithm>
//#include <memory>
using std::for_each;
using std::cout;
using std::endl;
using std::uninitialized_copy;
String::String(const char *init) {
	char *e = const_cast<char*>(init);
	while (*e)++e;
	range_initialize(init, ++e);
}
String::String(const String &init) {
	range_initialize(init.elements, init.end);
	cout << "String(const String &)" << endl;
}
String::String(String &&s) noexcept :elements(s.elements),end(s.end){
	s.elements = s.end = nullptr;
	cout << "String(String &&)" << endl;
}
String &String::operator=(const String &rhs) {
	auto str = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = str.first;
	end = str.second;
	cout << "String &operator=(const String &)" << endl;
	return *this;
}
String &String::operator=(String &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
		cout << "String &operator=(String &&)" << endl;
	}
	return *this;
}
pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
	auto str = alloc.allocate(e - b);
	return {str, uninitialized_copy(b,e,str)};
}
void String::range_initialize(const char *b, const char *e) {
	auto new_String = alloc_n_copy(b, e);
	elements = new_String.first;
	end = new_String.second;
}
void String::free() {
	if (elements) {
		for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
		elements = end = nullptr;
	}
}
ostream &operator<<(ostream &os, const String &str) {
	auto c = str.c_str();
	while (*c) os << *c++;
	return os;
}
bool operator==(const String &lhs, const String &rhs) {
	return lhs.size() == rhs.size() &&
		std::equal(lhs.elements, lhs.end, rhs.elements);
}
bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs) {
	return std::lexicographical_compare(lhs.elements, lhs.end, rhs.elements, rhs.end);
}
bool operator>(const String &lhs, const String &rhs) {
	return rhs < lhs;
}
bool operator<=(const String &lhs, const String &rhs) {
	return !(lhs > rhs);
}
bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs < rhs);
}