#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main() {
	cout << "singular: " << make_plural(1, "success") << " " << make_plural(1, "failure") << endl;
	cout << "plural: " << make_plural(2, "success", "es") << " " << make_plural(2, "failure") << endl;
	return 0;
}
