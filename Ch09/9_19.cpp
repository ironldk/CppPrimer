#include "stdafx.h"
#include <list>
#include <string>
#include <iostream>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<string> lst;
	for (string word; cin >> word; lst.push_back(word));
	for (auto iter = lst.cbegin(); iter != lst.cend(); ++iter)
		cout << *iter << endl;
	return 0;
}