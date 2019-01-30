#include "stdafx.h"
#include <iostream>
#include <vector>
using std::vector;

void print(const vector<int>& iv)
{
	for (auto i : iv) std::cout << i << " ";
	std::cout << std::endl;
}

void insertDoubleValue(vector<int>& iv, int some_val)
{
	auto cursor = iv.size() / 2;
	auto iter = iv.begin(), mid = iv.begin() + cursor;
	while (iter != mid) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;
			++cursor;
			mid = iv.begin() + cursor;
		}
		++iter;
		print(iv);
	}
}

int main()
{
	vector<int> iv = { 1, 1, 1, 1, 1, 7, 1, 9 };
	insertDoubleValue(iv, 1);
	// print(iv);
	return 0;
}