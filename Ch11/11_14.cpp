//Exercise 11.7: Define a map for which the key is the family¡¯s last name and
//the value is a vector of the children¡¯s names.Write code to add new
//families and to add new children to an existing family
//Exercise 11.14: Extend the map of children to their family name that you
//wrote for the exercises in ¡ì 11.2.1 (p. 424) by having the vector store a
//pair that holds a child¡¯s name and birthday
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
using std::vector;
using std::string;
using std::pair;
using std::map;
using std::cout;
using std::endl;
using std::cin;
int main() {
	map<string, vector<pair<string, string>>> family;
	string last_name;
	pair<string, string> child;
	while (cin >> last_name && last_name != "q") {
		while (cin >> child.first && child.first != "q")
		{
			cin >> child.second;
			family[last_name].push_back(child);
		}
	}
	for (const auto &f : family) {
		cout << endl << f.first << " family children: ";
		for (auto &c : f.second) { cout << c.first << " " << c.second << " "; }
	}
	return 0;
}