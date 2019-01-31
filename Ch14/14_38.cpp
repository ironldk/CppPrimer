//Exercise 14.38: Write a class that tests whether the length of a given
//string matches a given bound.Use that object to write a program to report
//how many words in an input file are of sizes 1 through 10 inclusive.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::for_each;
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
class IsLength {
public:
	IsLength(vector<int> &iv) :count(&iv) { count->resize(10); }
	void operator()(string &s) const {
		auto sz = s.size();
		if (sz > 0) {
			if(sz >= 10)
				++(*count)[9];
			else
				++(*count)[s.size() - 1];
		}
	}
private:
	vector<int> *count;
};

int main() {
	vector<int> ivec;
	vector<string> svec;
	string word;
	ifstream ifs("..\\..\\CppPrimerRepo\\Ch14\\14_38.txt");
	while (ifs >> word)	svec.push_back(word);
	for_each(svec.begin(), svec.end(), IsLength(ivec));
	for (auto i : ivec) {
		cout << i << " ";
	}
	return 0;
}