#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	list<int> l{ 1, 2, 3, 4, 5 };
	vector<int> vec2{ 1, 2, 3, 4, 5 };
	vector<int> vec3{ 1, 2, 3, 4 };
	cout << boolalpha
		 << (vector<int>(l.begin(), l.end()) == vec2) << endl;
	cout << boolalpha
		 << (vector<int>(l.begin(), l.end()) == vec3) << endl;
	return 0;
}