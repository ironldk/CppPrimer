#include"stdafx.h"
#include<iostream>
#include<forward_list>
#include<string>
using std::string;
using std::forward_list;
using std::cout;
using std::endl;
using std::distance;

int main() {
	// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
	forward_list<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
	auto prev = vi.before_begin();
		while (iter != vi.end()) {
			if (*iter % 2) {
				iter = vi.insert_after(iter, *iter); // duplicate the current element
					prev = iter++; // advance past this element and the one inserted before it
			}
			else
				iter = vi.erase_after(prev); // remove even elements
									   // don't advance the iterator; iter denotes the element after the one we erased
		}
	for (auto i : vi) {
		cout << i << endl;
	}
	return 0;
}