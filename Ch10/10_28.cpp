//Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
//into three other containers.Use an inserter, a back_inserter, and a
//front_inserter, respectivly to add elements to these containers.Predict
//how the output sequence varies by the kind of inserter and verify your
//predictions by running your programs
#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<iterator>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::for_each;
using std::ostream;
using std::back_inserter;
using std::front_inserter;
using std::inserter;
using std::copy;

int main() {
	ostream& out = cout;
	list<int> ilst1, ilst2, ilst3;
	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	copy(ivec.begin(), ivec.end(), back_inserter(ilst1));
	for_each(ilst1.begin(), ilst1.end(), [&out](const int& i) {out << i << " "; });
	copy(ivec.begin(), ivec.end(), front_inserter(ilst2));
	for_each(ilst2.begin(), ilst2.end(), [&out](const int& i) {out << i << " "; });
	copy(ivec.begin(), ivec.end(), inserter(ilst3, ilst3.begin()));
	for_each(ilst3.begin(), ilst3.end(), [&out](const int& i) {out << i << " "; });
	return 0;
}