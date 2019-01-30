#include "stdafx.h"
#include "StrBlob.h"
int main() {
	ifstream inputFile("in.txt");
	StrBlob text;
	string line;
	while (getline(inputFile, line)) {
		text.push_back(line);
	}
	for (ConstStrBlobPtr wp(text); wp.deref() != text.end().deref(); wp.incr()) {
		cout << wp.deref() << endl;
	}
	return 0;
}