//Exercise 10.5: In the call to equal on rosters, what would happen if both
//rosters held C - style strings, rather than library strings ?
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::equal;

int main() {
	vector<const char*> roster1 = { "1.5", "2.5", "3.5", "4.5", "5.5", "6.5", "7.5", "8.5", "9.5", "10.5" };
	list<const char*> roster2 = { "1.5", "2.5", "3.5", "4.5", "5.5", "6.5", "7.5", "8.5", "9.5", "10.5" };
	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;//loss of accuracy
	char c1[10] = "eipi10";
	char c2[10] = "eipi10";
	vector<char*> roster3{ c1 };
	list<char*> roster4{ c2 };
	cout << equal(roster3.cbegin(), roster3.cend(), roster4.cbegin());
	return 0;
}