#include "stdafx.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> iv;
	//cout << "using at: " << iv.at(0) << endl;
	//cout << "using subscript operator: " << iv[0] << endl;
	//cout << "using front: " << iv.front() << endl;
	cout << "using begin: " << *iv.begin() << endl;
	return 0;
}