#include "stdafx.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool hasCapital(const string &str) {
	for (auto iter = str.begin(); iter != str.end(); iter++) {
		cout << *iter;
		if (isupper(*iter)) {
			return true;
		}
	}
	return false;
}

void toLower(string &str) {
	for (auto iter = str.begin(); iter != str.end(); iter++) {
		//cout << toupper(*iter) << *iter << tolower(*iter) << *iter << endl;
		*iter = tolower(*iter);
		//cout << *iter << endl;
	}
}

int main() {
	string s = "i love It Hah!";
	cout << "Does \"" << s << "\" hasCapital?: " 
		<< (hasCapital(s) ? "yes" : "no") << endl;
	toLower(s);
	cout << "after toLower: " << s << endl;
	return 0;
}