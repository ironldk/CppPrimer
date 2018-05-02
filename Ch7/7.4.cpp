#include "stdafx.h"
#include <iostream>
//#include <string>
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

struct Person {
	Person() = default;
	Person(const string sname, const string saddr)
		: name(sname), address(saddr) 
	{
	}
	Person(istream is) { read(is, *this); }
	const string getName() const;
	const string getAddress() const;
public:
	string name;
	string address;
};

const string Person::getName() const {
	return name;
}

const string Person::getAddress() const {
	return address;
}

istream &read(istream &is, Person &person) {
	is >> person.name >> person.address;
	return is;
}

ostream &print(ostream &os, Person &person) {
	os << person.name << " " << person.address;
	return os;
}