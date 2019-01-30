#pragma once
#include "stdafx.h"
#include "StrBlob.h"
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
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
	return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
	return std::lexicographical_compare(lhs.data->begin(),
		lhs.data->end(), rhs.data->begin(), rhs.data->end());
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs > rhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs < rhs);
}
ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const {
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}
shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, const string &msg)
const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
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
ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
	++curr;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
	--curr;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
	ConstStrBlobPtr ret(*this);
	++*this;
	return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
	ConstStrBlobPtr ret(*this);
	--*this;
	return ret;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator+=(size_t n) {
	curr += n;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator-=(size_t n) {
	curr -= n;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator+(size_t n) const{
	ConstStrBlobPtr ret(*this);
	return ret += n;
}
ConstStrBlobPtr &ConstStrBlobPtr::operator-(size_t n) const{
	ConstStrBlobPtr ret(*this);
	return ret -= n;
}
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return /*lhs.wptr == rhs.wptr && */lhs.curr == rhs.curr;
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