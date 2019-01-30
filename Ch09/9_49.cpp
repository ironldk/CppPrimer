//Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter
//extends above the middle of the line.A letter has a descender if, as with p or
//g, part of the letter extends below the line.Write a program that reads a file
//containing words and reports the longest word that contains neither
//ascenders nor descenders
#include"stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main() {
	ifstream ifs("../data.txt");
	string word;
	string longest_word = "";
	if (!ifs)return -1;
	while (ifs >> word) {
		if (word.size() > longest_word.size()
			&& word.find_first_of("bdfghjiklpqty") == string::npos) {
			longest_word = word;
		}
	}
	cout << longest_word << endl;
	return 0;
}