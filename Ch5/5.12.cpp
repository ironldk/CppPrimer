#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
		spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch;
	char prech = '\0';
	while (cin >> std::noskipws >> ch) {
		switch (ch) {
		case 'a': case 'A':
			aCnt++;
			break;
		case 'e': case 'E':
			eCnt++;
			break;
		case 'i':
			if (prech == 'f') fiCnt++;
		case 'I':
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
		case 'f':
			if (prech == 'f') ffCnt++;
			break;
		case 'l':
			if (prech == 'f') flCnt++;
			break;
		default:
			break;
		}
		prech = ch;
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of spaces: \t" << spaceCnt << '\n'
		<< "Number of tabs: \t" << tabCnt << '\n'
		<< "Number of newlines: \t" << newLineCnt << '\n'
		<< "Number of ff: \t" << ffCnt << '\n'
		<< "Number of fl: \t" << flCnt << '\n'
		<< "Number of fi: \t" << fiCnt << endl;
	return 0;
}