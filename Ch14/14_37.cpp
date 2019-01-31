#include "stdafx.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>
using std::replace_if;
using std::vector;
using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
class IsEqual {
public:
	IsEqual(int v):element(v){}
	bool operator()(int value) const {
		return value == element;
	}
private:
	int element;
};

int main() {
	vector<int> ivec{ 3, 2, 1, 4, 3, 7, 8, 6 };
	replace_if(ivec.begin(), ivec.end(), IsEqual(3), 5);
	for (auto i : ivec) {
		cout << i << " ";
	}
	return 0;
}