#include "stdafx.h"
#include <vector>
using std::vector;
bool find(vector<int>::iterator beg,
	vector<int>::iterator end, int value) {
	for (auto iter = beg; iter != end; ++iter)
		if (*iter == value) return true;
	return false;
}