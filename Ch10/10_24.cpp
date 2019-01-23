//Exercise 10.25: In the exercises for ¡ì 10.3.2 (p. 392) you wrote a version
//of biggies that uses partition.Rewrite that function to use
//check_size and bind
#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using std::string;
using std::vector;
using std::bind;
using std::cout;
using std::endl;
using std::placeholders::_1;
using std::ref;

bool check_size(const int &s, size_t sz)
{
	return s >= sz;
}

int main() {
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
	string str = "fuck";
	auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, _1, str.size()));
	cout << *iter << endl;
	return 0;
}