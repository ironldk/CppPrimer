// Exercise 9.43: Write a function that takes three strings, s, oldVal, and
// newVal.Using iterators, and the insert and erase functions replace all
// instances of oldVal that appear in s by newVal.Test your function by
// using it to replace common abbreviations, such as ¡°tho¡± by ¡°though¡± and
//¡°thru¡± by ¡°through¡±
// Exercise 9.44: Rewrite the previous function using an index and replace
#include"stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

void find_and_replace(string &s, const string &oldVal, const string &newVal) {
	for (string::size_type iter = 0; iter <= s.size() - oldVal.size(); iter++) {
		if (s.substr(iter, oldVal.size()) == oldVal) {
			s.replace(iter, oldVal.size(), newVal);
			iter += newVal.size() - 1;
		}
	}
}

int main() {
	string str = "go thru, went thru, gone thru, going thru";
	cout << str << endl;
	find_and_replace(str, "thru", "through");
	cout << str << endl;
	return 0;
}