#pragma once
#include <ostream>
#include <iostream>
using std::ostream;
using std::cerr;
using std::endl;
// function-object class that calls delete on a given pointerC++ Primer, Fifth Edition
class DebugDelete {
public:
	DebugDelete(ostream &s = cerr) : os(s) { }
	// as with any function template, the type of T is deduced by the compiler
	template <typename T> void operator()(T *p) const {
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};