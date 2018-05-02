#include "stdafx.h"
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string word, preWord;
	while (cin >> word) {
		if (!isupper(word[0])) continue;
		if (word == preWord) {
			break;
		} else {
			preWord = word;
		}
	}
	if (cin.eof()) {
		cout << "no word was repeated." << endl;
	} else {
		cout << word << " was repeated twice in succesion" << endl;
	}
	return 0;
}