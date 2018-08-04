#include "stdafx.h"
#include "7_41_Sales_data.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;

// Exercise 8.8: Revise the program from the previous exercise to append its
// output to its given file.Run the program on the same output file at least
// twice to ensure that the data are preserved.
/*
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
*/
int main(int argc, char** argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2], ofstream::app);
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