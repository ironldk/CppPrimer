#include "stdafx.h"
#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string curr, last = "", maxRepStr;
	int numOfRep = 0, maxRep = 0;
	while (cin>>curr) {
		if (curr == last) {
			numOfRep++;
		}
		else {
			numOfRep = 1;
		}
		if (numOfRep > maxRep) {
			maxRep = numOfRep;
			maxRepStr = curr;
		}
		last = curr;
	}
	if (maxRep <= 1) {
		cout << "No word was repeated!" << endl;
	} else {
		cout << maxRepStr << " was repeated " << maxRep << " times." << endl;
	}
	return 0;
}