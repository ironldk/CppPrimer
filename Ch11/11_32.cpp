//Exercise 11.31: Write a program that defines a multimap of authors and
//their works.Use find to find an element in the multimap and erase that
//element.Be sure your program works correctly if the element you look for is
//not in the map.
//Exercise 11.32: Using the multimap from the previous exercise, write a
//program to print the list of authors and their works alphabetically.
#include "stdafx.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
using std::string;
using std::multimap;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::cin;
int main() {
	multimap<string, string> authors{ { "alan", "DMA" }, { "pezy", "LeetCode" }, { "alan", "CLRS" },
	{ "wang", "FTP" }, { "pezy", "CP5" }, { "wang", "CPP-Concurrency" }
	};
	map<string, set<string>> ordered_works;
	for (auto author : authors) {
		ordered_works[author.first].insert(author.second);
	}
	for (const auto &f : ordered_works) {
		cout << "Author " << f.first << " have works: ";
		for (const auto &work : f.second) {
			cout << work << " ";
		}cout << endl;
	}
	for (const auto &f : authors) {
		cout << "Author " << f.first << " have work: " << f.second << endl;
	}
	return 0;
}