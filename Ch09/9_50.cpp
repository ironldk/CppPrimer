//Exercise 9.50: Write a program to process a vector<string>s whose
//elements represent integral values.Produce the sum of all the elements in
//that vector.Change the program so that it sums of strings that represent
//floating - point values
#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<string> nums{ "1", "2", "3", "4.5" };
	int sumi = 0;
	float sumf = 0;
	for (auto s : nums){
		sumi += stoi(s);
		sumf += stof(s);
	}
	cout << sumi << " " << sumf << endl;
	return 0;
}