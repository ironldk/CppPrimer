#pragma once
#include "stdafx.h"
#include "StrVec.h"
#include <memory>
#include <initializer_list>
using std::initializer_list;
using std::uninitialized_copy;
void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements; /* empty */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
		elements = first_free = cap = nullptr;
	}
}
StrVec::StrVec(const StrVec &s) {
	range_initialize(s.begin(), s.end());
}
StrVec::StrVec(StrVec &&s)noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap){
	s.elements = s.first_free = s.cap = nullptr;
}
StrVec::StrVec(initializer_list<string> il) {
	range_initialize(il.begin(), il.end());
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
StrVec &StrVec::operator=(StrVec &&rhs)noexcept{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
StrVec &StrVec::operator=(initializer_list<string> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
bool operator==(const StrVec &lhs, const StrVec &rhs) {
	return lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs) {
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
bool operator>(const StrVec &lhs, const StrVec &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs > rhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs < rhs);
}
void StrVec::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	reallocate(newcapacity);
}
void StrVec::reallocate(size_t newcapacity) {
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
void StrVec::reserve(size_t new_cap) {
	if (new_cap > capacity())reallocate(new_cap);
}
void StrVec::resize(size_t new_size, const string &s) {
	if (new_size > size()) {
		reserve(new_size);
		while(first_free != elements + new_size)
			alloc.construct(first_free++, s);
	}
	else if (new_size < size()) {
		while (first_free != elements + new_size)
			alloc.destroy(--first_free);
	}
}
void StrVec::range_initialize(const string* begin, const string* end) {
	auto newdata = alloc_n_copy(begin, end);
	elements = newdata.first;
	first_free = cap = newdata.second;
}