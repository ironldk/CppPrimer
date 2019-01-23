//Exercise 10.27: In addition to unique(¡ì 10.2.3, p. 384), the library
//defines function named unique_copy that takes a third iterator denoting a
//destination into which to copy the unique elements.Write a program that
//uses unique_copy to copy the unique elements from a vector into an
//initially empty list
//the quick red fox jumps over the slow red turtle
#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;
using std::unique_copy;
using std::for_each;
using std::ostream;
using std::back_inserter;
using std::sort;

int main() {
	ostream& out = cout;
	list<string> slst;
	vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	sort(svec.begin(), svec.end());
	unique_copy(svec.begin(), svec.end(), back_inserter(slst));
	for_each(slst.begin(), slst.end(), [&out](const string& a) {out << a << " "; });
	return 0;
}