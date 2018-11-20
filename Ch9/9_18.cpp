#include "stdafx.h"
#include <deque>
#include <string>
#include <iostream>
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	deque<string> sdeq;
	for (string word; cin >> word; sdeq.push_back(word));
	for (auto iter = sdeq.cbegin(); iter != sdeq.cend(); ++iter)
		cout << *iter << endl;
	return 0;
}