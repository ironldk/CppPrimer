//Exercise 11.33: Implement your own version of the word - transformation
//program
//Exercise 11.38: Rewrite the word - counting(¡ì 11.1, p. 421) and 
//wordtransformation(¡ì 11.3.6, p. 440) programs to use an unordered_map.
#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
using std::string;
using std::runtime_error;
using std::unordered_map;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cin;

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map; // holds the transformations
	string key; // a word to transform
	string value; // phrase to use instead
				  // read the first word into key and the rest of the line into value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1) // check that there is a transformation
			trans_map[key] = value.substr(1); // skip leading space
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
	// the actual map work; this part is the heart of the program
	auto map_it = m.find(s);
	// if this word is in the transformation map
	if (map_it != m.cend())
		return map_it->second; // use the replacement word
	else
		return s; // otherwise return the original unchanged
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); // store the transformations
	string text; // hold each line from the input
	while (getline(input, text)) { // read a line of input
		istringstream stream(text); // read each word
		string word;
		bool firstword = true; // controls whether a space is printed
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " "; // print a space between words
							 // transform returns its first argument or its transformation
			cout << transform(word, trans_map); // print the output
		}
		cout << endl; // done with this line of input
	}
}

int main() {
	ifstream map("map.txt"), text("text.txt");
	word_transform(map, text);
	return 0;
}