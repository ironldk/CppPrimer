//Exercise 11.7: Define a map for which the key is the family¡¯s last name and
//the value is a vector of the children¡¯s names.Write code to add new
//families and to add new children to an existing family
//Exercise 11.23: Rewrite the map that stored vectors of children¡¯s names
//with a key that is the family last name for the exercises in ¡ì 11.2.1 (p. 424)
//to use a multimap.
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::multimap;
using std::cout;
using std::endl;
using std::cin;
int main() {
	multimap<string, string> family;
	string last_name, child_name;
	while (cin >> last_name >> child_name) {
		family.emplace(last_name, child_name);
		//family[last_name]; //multimap cannot use subscript op
		//cause it has multiple value related to the wanted key
	}
	for (const auto &f : family) {
		cout << f.second << f.first << endl;
	}
	return 0;
}