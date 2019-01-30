#include"stdafx.h"
#include<fstream>
#include <iostream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

// Write a function to open a file for input and read its contents
// into a vector of strings, storing each line as a separate element in the
// vector.
void func(const string &ifile, vector<string> &vec) {
	ifstream in(ifile);
	if (in) {
		string word;
		while (in >> word)
		{
			vec.push_back(word);
		}
	}

}

int main() {
	string ifile = "lena.txt";
	vector<string> vec;
	func(ifile, vec);
	for (const auto& str : vec)
	{
		cout << str << endl;
	}
	return 0;
}