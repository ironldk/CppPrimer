#pragma once
#include "stdafx.h"
#include <string>
using std::string;
class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
public:
	HasPtr(const string &s = string());
	HasPtr(HasPtr &&)noexcept;
	HasPtr(const HasPtr &);
	//HasPtr &operator=(HasPtr);
	HasPtr &operator=(const HasPtr &);
	HasPtr &operator=(HasPtr &&)noexcept;
	~HasPtr();
private:
	string * ps;
	int i;
	size_t * use;
};