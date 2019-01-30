#include"stdafx.h"
#include<iostream>
#include<vector>
#include<list>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::end;
using std::begin;

int main() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> iv(begin(ia), end(ia));
	list<int> il(begin(ia), end(ia));
	/*
	for (int idx = 0; idx < end(ia) - begin(ia); idx++) {
		iv.push_back(ia[idx]);
		il.push_back(ia[idx]);
	}
	*/

	auto iter = il.begin();
	while (iter != il.end()) {
		if (*iter % 2) { iter = il.erase(iter); }
		else { iter++; }
	}

	auto it = iv.begin();
	while (it != iv.end()) {
		if (!(*it % 2)) { it = iv.erase(it); }
		else { it++; }
	}

	cout << "il:" << endl;
	for (auto iter = il.begin(); iter != il.end(); iter++) {
		cout << *iter << endl;
	}
	
	cout << "iv:" << endl;
	for (auto iter = iv.begin(); iter != iv.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}