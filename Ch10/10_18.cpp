//Exercise 10.18: Rewrite biggies to use partition instead of find_if.
//We described the partition algorithm in exercise 10.13 in ¡ì 10.3.1 (p.
//387)
//the quick red fox jumps over the slow red turtle
#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::partition;
using std::vector;
using std::string;
using std::stable_sort;
using std::sort;
using std::unique;
using std::for_each;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word,
	const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
	// sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	auto end_unique = unique(words.begin(), words.end());
	// erase uses a vector operation to remove the nonunique elements
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words,
	vector<string>::size_type sz)
{
	elimDups(words); // put words in alphabetical order and remove duplicates
		// sort words by size, but maintain alphabetical order for words of the same size
		stable_sort(words.begin(), words.end(),
			[](const string &a, const string &b)
	{ return a.size() < b.size(); });
	// get an iterator to the first element whose size() is >= sz
	auto wc = partition(words.begin(), words.end(),
		[sz](const string &a)
	{ return a.size() < sz; });
	// compute the number of elements with size >= sz
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	// print words of the given size or longer, each one followed by a space
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main() {
	vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(svec, 4);
	return 0;
}