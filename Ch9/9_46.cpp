//Exercise 9.45: Write a funtion that takes a string representing a name
//and two other strings representing a prefix, such as ¡°Mr.¡± or ¡°Ms.¡± and a
//suffix, such as ¡°Jr.¡± or ¡°III¡±.Using iterators and the insert and append
//functions, generate and return a new string with the suffix and prefix
//added to the given name
//Exercise 9.46: Rewrite the previous exercise using a position and length to
//manage the strings.This time use only the insert function
#include"stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

void insert_prefix_and_suffix(string &name, const string &prefix, const string &suffix) {
	name.insert(0, prefix);
	name.insert(name.size(), suffix);
}

int main() {
	string str = "Trump";
	cout << str << endl;
	insert_prefix_and_suffix(str, "Mr.", "III");
	cout << str << endl;
	return 0;
}