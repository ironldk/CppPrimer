#include "stdafx.h"
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string str;
	do {
		string s1, s2;
		cout << "input string 1: ";
		getline(cin, s1);
		cout << "input string 2: ";
		getline(cin, s2);

		cout << s1 << endl;
		cout << s2 << endl;

		if (s1 < s2) {
			cout << "string 1 is less than string 2." << endl;
		} else if (s2 < s1){
			cout << "string 2 is less than string 1." << endl;
		} else {
			cout << "string 1 is the same as string 2." << endl;
		}
		cin >> str;
	} while (!str.empty() && str[0] != 'n');
	return 0;
}