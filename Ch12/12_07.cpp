//Exercise 12.6: Write a function that returns a dynamically allocated vector
//of ints.Pass that vector to another function that reads the standard input
//to give values to the elements.Pass the vector to another function to print
//the values that were read.Remember to delete the vector at the
//appropriate time
//Exercise 12.7: Redo the previous exercise, this time using shared_ptr
#include"stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> alloc_ivec() {
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> input(shared_ptr<vector<int>> p) {
	int i;
	while (cin >> i) {
		p->push_back(i);
	}
	return p;
}

void output(shared_ptr<vector<int>> p) {
	for (int i : *p) {
		cout << i << " ";
	}
}

int main() {
	output(input(alloc_ivec()));
	return 0;
}