// 9.41 Write a program that initializes a string from a vector<char>
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<char> vec = {'H','e','l','l','o',' ','W','o','r','l','d','!'};
	string str(vec.begin(), vec.end()); // sequential container's generic operation
  	for (auto c : str) {
		cout << c << endl;
	}
	return 0;
}