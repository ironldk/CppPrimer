//Exercise 12.24: Write a program that reads a string from the standard input
//into a dynamically allocated character array.Describe how your program
//handles varying size inputs.Test your program by giving it a string of data
//that is longer than the array size you¡¯ve allocated
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
	size_t s = 0;
	cout << "size: ";
	cin >> s;
	char *h = new char[s + 1]();
	cin.ignore();
	cin.get(h, s + 1);
	cout << h << endl;
	delete[] h;
	return 0;
}