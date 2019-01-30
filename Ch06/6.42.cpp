#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>

using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::string;

// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

int main(void)
{
	string a = "123", b = "1234";
	cout << shorterString(a, b) << endl;
	return 0;
}

int func(int, int);
vector<func*> vecF;