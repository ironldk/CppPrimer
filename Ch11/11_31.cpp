//Exercise 11.31: Write a program that defines a multimap of authors and
//their works.Use find to find an element in the multimap and erase that
//element.Be sure your program works correctly if the element you look for is
//not in the map.
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using std::string;
using std::multimap;
using std::cout;
using std::endl;
using std::cin;
int main() {
	multimap<string, string> authors;
	string author, work;
	auto found = authors.find(author);
	auto count = authors.count(author);
	while (count)
	{
		if (found->second == work)
		{
			authors.erase(found);
			break;
		}
		++found;
		--count;
	}
	for (const auto &f : authors) {
		cout << f.second << f.first << endl;
	}
	return 0;
}