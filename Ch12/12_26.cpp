//Exercise 12.26: Rewrite the program on page 481 using an allocator
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::allocator;
using std::string;
using std::unique_ptr;
using std::uninitialized_copy;
using std::cout;
using std::endl;
using std::cin;

int main() {
	allocator<string> alloc;
	size_t n = 10;
	auto const p = alloc.allocate(n);
	//string *const p = new string[n]; // construct n empty strings
	string s;
	string *q = p; // q points to the first string
	while (cin >> s && q != p + n) {
		alloc.construct(q, s);
		++q;
		//*q++ = s; // assign a new value to *q
	}
	const size_t size = q - p; // remember how many strings we read
		// use the array
		//delete[] p; // p points to an array; must remember to use delete[]
	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
		return 0;
}