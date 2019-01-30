#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<string> lst;
	string word;
	auto iter = lst.begin();
	while (cin >> word)
		iter = lst.insert(iter, word);
	for (auto s : lst) cout << s << endl;
	return 0;
}