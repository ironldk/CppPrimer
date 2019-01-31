#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::getline;

// Exercise 8.6: Rewrite the bookstore program from ¡ì 7.1.1 (p. 256) to read
// its transactions from a file.Pass the name of the file as an argument to main
// (¡ì 6.2.5, p. 218)

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	Sales_data total; // variable to hold the running sum
	if (read(in, total)) { // read the first transaction
		Sales_data trans; // variable to hold data for the next transaction
		while (read(in, trans)) { // read the remaining transactions
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
	return 0;
}