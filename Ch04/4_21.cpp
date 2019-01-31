#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main() {
	vector<int> vec = { 0,1,2,3,4,5,6,7,8,9,10 };
	auto beg = vec.begin();
	auto end = vec.end();
	for (auto iter = beg; iter != end; iter++) {
		(*iter % 2) ? (*iter *= 2) : (1);
		cout << *iter << endl;
	}
	string s = "word";
	string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << pl;
	return 0;
}