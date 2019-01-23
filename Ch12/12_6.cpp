//Exercise 12.6: Write a function that returns a dynamically allocated vector
//of ints.Pass that vector to another function that reads the standard input
//to give values to the elements.Pass the vector to another function to print
//the values that were read.Remember to delete the vector at the
//appropriate time
#include"stdafx.h"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> *alloc_ivec() {
	return new vector<int>;
}

vector<int> *input(vector<int> *p) {
	int i;
	while (cin >> i) {
		p -> push_back(i);
	}
	return p;
}

void output(vector<int> *p) {
	for (int i : *p){
		cout << i << " ";
	}
	delete p;
}

int main() {
	output(input(alloc_ivec()));
	return 0;
}