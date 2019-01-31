//Exercise 11.7: Define a map for which the key is the family¡¯s last name and
//the value is a vector of the children¡¯s names.Write code to add new
//families and to add new children to an existing family
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::cin;
int main() {
	map<string, vector<string>> family;
	string last_name, child_name;
	while (cin >> last_name && last_name != "q") {
		while (cin >> child_name && child_name != "q")
		{
			family[last_name].push_back(child_name);
		}
	}
	for (const auto &f : family) {
		cout << endl << f.first << " family children: ";
		for (auto &c : f.second) { cout << c << " "; }
	}
	return 0;
}