#include "stdafx.h"
#include <list>
#include <deque>
#include <string>
#include <iostream>
using std::list;
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<int> input{0,1,2,3,4,5};
	deque<int> even, odd;
	for (auto num : input)
		(num & 1 ? odd : even).push_back(num);
	for (auto iter = even.cbegin(); iter != even.cend(); ++iter)
		cout << "even: " << *iter << endl;
	for (auto iter = odd.cbegin(); iter != odd.cend(); ++iter)
		cout << "odd: " << *iter << endl;
	return 0;
}