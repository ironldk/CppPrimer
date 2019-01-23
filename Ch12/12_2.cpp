//Exercise 12.2: Write your own version of the StrBlob class including the
//const versions of front and back
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

class StrBlob {
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
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
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

int main() {
	StrBlob a = { "a", "b", "c" };
	const StrBlob b = { "a", "b", "c", "d" };
	cout << a.front() << " " << a.back() << endl;
	cout << b.front() << " " << b.back() << endl;
	return 0;
}