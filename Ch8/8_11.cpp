//Exercise 8.11: The program in this section defined its istringstream
//object inside the outer while loop.What changes would you need to make if
//record were defined outside that loop ? Rewrite the program, moving the
//definition of record outside the while, and see whether you thought of all
//the changes that are needed.
#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::istringstream;
using std::cin;

// members are public by default; see ¡ì 7.2 (p. 268)
struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word; // will hold a line and word from input, respectivelyC++ Primer, Fifth Edition
	vector<PersonInfo> people; // will hold all the records from the input
							   // read the input a line at a time until cin hits end-of-file (or another error)
	istringstream record; // bind record to the line we just read
	while (getline(cin, line)) {
		PersonInfo info; // create an object to hold this record's data
		record.clear();
		record.str(line);
		record >> info.name; // read the name
		while (record >> word) // read the phone numbers
			info.phones.push_back(word); // and store them
		people.push_back(info); // append this record to people
	}
	return 0;
}