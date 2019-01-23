//Exercise 12.23: Write a program to concatenate two string literals, putting
//the result in a dynamically allocated array of char.Write a program to
//concatenate two library strings that have the same value as the literals
//used in the first program
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;
using std::cin;

int main() {
	const char *f = "love ", *g = "me";
	size_t s = strlen(f) + strlen(g) + 1;
	char *h = new char[s]();
	strcat_s(h, s, f);
	strcat_s(h, s, g);
	cout << h << endl;
	string a("hello "), b("world!");
	size_t s2 = a.length() + b.length() + 1;
	char *c = new char[s2]();
	strcat_s(c, s2, a.c_str());
	strcat_s(c, s2, b.c_str());
	cout << c << endl;
	delete[] h;
	delete[] c;
	return 0;
}