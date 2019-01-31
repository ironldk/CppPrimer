//Exercise 14.35: Write a class like PrintString that reads a line of input
//from an istream and returns a string representing what was read.If the
//read fails, return the empty string.
//Exercise 14.36: Use the class from the previous exercise to read the
//standard input, storing each line as an element in a vector.
#include "stdafx.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
class ReadString {
public:
	ReadString(istream &is = cin) :i(is) {}
	string operator()() {
		string a;
		getline(i, a);
		return i ? a : "";
	}
private:
	istream & i;
};

int main() {
	ReadString rs;
	vector<string> svec;
	for (string s; !(s = rs()).empty();) { svec.push_back(s); }
	for (string s : svec)cout << s << endl;
	return 0;
}