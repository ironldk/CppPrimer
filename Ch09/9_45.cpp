//Exercise 9.45: Write a funtion that takes a string representing a name
//and two other strings representing a prefix, such as ¡°Mr.¡± or ¡°Ms.¡± and a
//suffix, such as ¡°Jr.¡± or ¡°III¡±.Using iterators and the insert and append
//functions, generate and return a new string with the suffix and prefix
//added to the given name
#include"stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

void insert_and_append(string &name, const string &prefix, const string &suffix) {
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(suffix);
}

int main() {
	string str = "Trump";
	cout << str << endl;
	insert_and_append(str, "Mr.", "III");
	cout << str << endl;
	return 0;
}