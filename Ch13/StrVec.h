#pragma once
#include <string>
#include <initializer_list>
using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;
class StrVec {
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(const StrVec&);
	StrVec(StrVec&&)noexcept;
	StrVec(initializer_list<string>);
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec&&)noexcept;
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	void reserve(size_t);
	size_t capacity() const { return cap - elements; }
	void resize(size_t, const string &);
	void resize(size_t count) { resize(count, string()); }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
private:
	/*static */allocator<string> alloc;
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	pair<string*, string*> alloc_n_copy
	(const string*, const string*);
	void free();
	void reallocate();
	void reallocate(size_t);
	void range_initialize(const string*, const string*);
	string *elements;
	string *first_free;
	string *cap;
};