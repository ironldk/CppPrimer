#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::getline;

// Exercise 8.7: Revise the bookstore program from the previous section to
// write its output to a file.Pass the name of that file as a second argument to
// main.

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	Sales_data total; // variable to hold the running sum
	if (read(in, total)) { // read the first transaction
		Sales_data trans; // variable to hold data for the next transaction
		while (read(in, trans)) { // read the remaining transactions
			if (total.isbn() == trans.isbn()) // check the isbns
				total.combine(trans); // update the running total
			else {
				print(out, total) << endl; // print the results
				total = trans; // process the next book
			}
		}
		print(out, total) << endl; // print the last transaction
	}
	else { // there was no input
		cerr << "No data?!" << endl; // notify the user
	}
	return 0;
}