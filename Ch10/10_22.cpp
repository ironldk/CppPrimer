//Exercise 10.22: Rewrite the program to count words of size 6 or less using
//functions in place of the lambdas.
//the quick red fox jumps over the slow red turtle
#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using std::string;
using std::vector;
using std::for_each;
using std::bind;
using std::cout;
using std::endl;
using std::placeholders::_1;
using std::ref;

void six_or_less_char(const string &s, int &counter) {
	if (s.size() <= 6) ++counter;
}

int main() {
	vector<string> str = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	int c = 0;
	for_each(str.begin(), str.end(), bind(six_or_less_char, _1, ref(c)));
	cout << c << endl;
	return 0;
}