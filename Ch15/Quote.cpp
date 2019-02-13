#include "Quote.h"
double Quote::net_price(std::size_t n) const {
	return n * price;
}
void Quote::debug() const {
	cout << "data members: \n";
	cout << "\tbookNo: " << bookNo << "\tprice: " << price << endl;
}