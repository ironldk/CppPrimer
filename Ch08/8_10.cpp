#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cerr;

int main() {
	ifstream myFile("pretendToHaveAFile.txt");
	if (myFile) {
		cerr << "No data?" << endl;
		return -1;
	}
	vector<string> vstr;
	string line;
	while (getline(myFile, line)) vstr.push_back(line);
	
	for (auto& iter : vstr) {
		istringstream iss(iter);
		string word;
		while (iss >> word) cout << word << endl;
	}
	return 0;
}