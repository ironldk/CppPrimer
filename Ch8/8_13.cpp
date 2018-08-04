//Exercise 8.13: Rewrite the phone number program from this section to read
//from a named file rather than from cin.
#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;
using std::cerr;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;

// members are public by default; see ¡ì 7.2 (p. 268)
struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const string& str) {
	return isdigit(str[0]);
}

string format(const string& str) {
	return str.substr(0, 3)+'-'+str.substr(3, 3)+'-'+str.substr(6);
}

int main() {
	ifstream ifs("phonenumbers.txt");
	if (!ifs) {
		cerr << "File not found!" << endl;
		return -1;
	}
	string line, word; // will hold a line and word from input, respectivelyC++ Primer, Fifth Edition
	vector<PersonInfo> people; // will hold all the records from the input
							   // read the input a line at a time until cin hits end-of-file (or another error)
	istringstream record; // bind record to the line we just read
	while (getline(ifs, line)) {
		PersonInfo info; // create an object to hold this record's data
		record.clear();
		record.str(line);
		record >> info.name; // read the name
		while (record >> word) // read the phone numbers
			info.phones.push_back(word); // and store them
		people.push_back(info); // append this record to people
	}
	for (const auto &entry : people) { // for each entry in people
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) { // for each number
			if (!valid(nums)) {
				badNums << " " << nums; // string in badNums
			}
			else
				// ''writes'' to formatted's string
				formatted << " " << format(nums);
		}
		if (badNums.str().empty()) // there were no bad numbers
			cout << entry.name << " " // print the name
			<< formatted.str() << endl; // and reformatted numbers
		else // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name
			<< " invalid number(s) " << badNums.str() <<
			endl;
	}
	return 0;
}