//Exercise 10.42: Reimplement the program that eliminated duplicate words
//that we wrote in ¡ì 10.2.3 (p. 383) to use a list instead of a vector.
//the quick red fox jumps over the slow red turtle
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <string>
using std::list;
using std::string;
using std::sort;

void elimDups(list<string> &words)
{
	// sort words alphabetically so we can find the duplicates
	words.sort();
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	words.unique();
}

int main() {
	list<string> slst = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(slst);
	return 0;
}