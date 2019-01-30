#include"stdafx.h"
#include<iostream>
#include<forward_list>
using std::forward_list;
using std::cout;
using std::endl;

int main() {
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	// denotes the first element in flst
	for (auto prev = flst.before_begin(), // denotes element "off the start" of flst
		curr = flst.begin(); curr != flst.end(); ) { // while there are still elements to process
		if (*curr % 2) // if the element is odd
			curr = flst.erase_after(prev); // erase it and move curr
		else
			prev = curr++; // move the iterators to denote the next element and one before the next element
	}
	for (auto i : flst) {
		cout << i << endl;
	}
	return 0;
}