//Exercise 9.47: Write a program that finds each numeric character and then
//each alphabetic character in the string "ab2c3d7R4E6".Write two
//versions of the program.The first should use find_first_of, and the
//second find_first_not_of
#include"stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

void find_numeric_and_alphabetic_using_find_first_of(const string &str) {
	string::size_type pos = 0;
	while ((pos = str.find_first_of("0123456789", pos)) != string::npos) {
		cout << "found numeric " << str[pos] << " at position " << pos << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos)) != string::npos) {
		cout << "found alphabetic " << str[pos] << " at position " << pos << endl;
		++pos;
	}
}

void find_numeric_and_alphabetic_using_find_first_not_of(const string &str) {
	string::size_type pos = 0;
	while ((pos = str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos)) != string::npos) {
		cout << "found numeric " << str[pos] << " at position " << pos << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of("0123456789", pos)) != string::npos) {
		cout << "found alphabetic " << str[pos] << " at position " << pos << endl;
		++pos;
	}
}


int main() {
	string str{ "ab2c3d7R4E6" };
	find_numeric_and_alphabetic_using_find_first_of(str);
	find_numeric_and_alphabetic_using_find_first_not_of(str);
	return 0;
}