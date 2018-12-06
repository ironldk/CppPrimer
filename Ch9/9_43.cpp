// Exercise 9.43: Write a function that takes three strings, s, oldVal, and
// newVal.Using iterators, and the insert and erase functions replace all
// instances of oldVal that appear in s by newVal.Test your function by
// using it to replace common abbreviations, such as ¡°tho¡± by ¡°though¡± and
//¡°thru¡± by ¡°through¡±
#include"stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

void find_and_replace(string &s, const string &oldVal, const string &newVal) {
	for (auto iter = s.begin(); iter <= s.end() - oldVal.size(); iter++) {
		//cout << string(iter, iter + oldVal.size()) << endl;
		if (string(iter, iter + oldVal.size()) == oldVal) {
			iter = s.erase(iter, iter + oldVal.size());
			//cout << s << endl;
			//iterator only valid before insertion point if no reallocation
			iter = s.insert(iter, newVal.begin(), newVal.end());
			//cout << s << endl;
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