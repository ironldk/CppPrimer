#include"stdafx.h"
#include<fstream>
#include <iostream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

// Exercise 8.6: Rewrite the bookstore program from ¡ì 7.1.1 (p. 256) to read
// its transactions from a file.Pass the name of the file as an argument to main
// (¡ì 6.2.5, p. 218)
void func(const string &ifile, vector<string> &vec) {
	ifstream in(ifile);
	if (in) {
		string word;
		while (in >> word)
		{
			vec.push_back(word);
		}
	}

}

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data total; // variable to hold the running sum
if (read(cin, total)) { // read the first transaction
	Sales_data trans; // variable to hold data for the next transaction
	while (read(cin, trans)) { // read the remaining transactions
		if (total.isbn() == trans.isbn()) // check the isbns
			total.combine(trans); // update the running total
		else {
			print(cout, total) << endl; // print the results
			total = trans; // process the next book
		}
	}
	print(cout, total) << endl; // print the last transaction
}
else { // there was no input
	cerr << "No data?!" << endl; // notify the user
}

int main(int argc, char** argv) {
	
	string ifile = "lena.txt";
	vector<string> vec;
	func(ifile, vec);
	for (const auto& str : vec)
	{
		cout << str << endl;
	}
	return 0;
}