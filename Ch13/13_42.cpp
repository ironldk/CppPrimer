#pragma once
//Exercise 12.27: The TextQuery and QueryResult classes use only
//capabilities that we have already covered.Without looking ahead, write your
//own versions of these classes
//element occurs 112 times
//(line 36) A set element contains only a key;
//(line 158) operator creates a new element
//(line 160) Regardless of whether the element
//(line 168) When we fetch an element from a map, we
//(line 214) If the element is not found, find returns
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "StrVec.h"
#include "TextQueryStrVec.h"
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void runQueries(ifstream &infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile); // store the file and build the query map
						  // iterate with the user: prompt for a word to find and print results
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		// stop if we hit end-of-file on the input or if a 'q' is entered
		if (!(cin >> s) || s == "q") break;
		// run the query and print the results
		print(cout, tq.query(s)) << endl;
	}
}
int main() {
	ifstream text("12_27.txt");
	runQueries(text);
	return 0;
}