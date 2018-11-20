#include "stdafx.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	vector<int> vec1{ 1, 2, 3, 4, 5 };
	vector<int> vec2{ 1, 2, 3, 4, 5 };
	vector<int> vec3{ 1, 2, 3, 4 };

	cout << boolalpha << (vec1 == vec2) << endl;
	cout << boolalpha << (vec1 == vec3) << endl;

	return 0;
}