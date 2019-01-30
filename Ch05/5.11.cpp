#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
	char ch;
	while (cin >> std::noskipws >> ch) {
		switch (ch) {
		case 'a': case 'A':
			aCnt++;
			break;
		case 'e': case 'E':
			eCnt++;
			break;
		case 'i': case 'I':
			iCnt++;
			break;
		case 'o': case 'O':
			oCnt++;
			break;
		case 'u': case 'U':
			uCnt++;
			break;
		case ' ':
			spaceCnt++;
			break;
		case '\t':
			tabCnt++;
			break;
		case '\n':
			newLineCnt++;
			break;
		default:
			break;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of spaces: \t" << spaceCnt << '\n'
		<< "Number of tabs: \t" << tabCnt << '\n'
		<< "Number of newlines: \t" << newLineCnt << endl;
}