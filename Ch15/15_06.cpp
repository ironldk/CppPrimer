#pragma once
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n) {
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // calls Quote::isbn
		<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
int main() {
	Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);
	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);
	Disc_quote a;
	return 0;
}