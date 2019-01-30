// 9.38 Write a program to explore how vectors grow in the library you use
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vi;
	cout << "size: " << vi.size() << " capacity: " << vi.capacity() << endl;
	for (int i = 0; i < 100; i++) {
		vi.push_back(i);
		cout << "size: " << vi.size() << " capacity: " << vi.capacity() << endl;
	}
	return 0;
}