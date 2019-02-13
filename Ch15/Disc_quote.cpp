#include "Disc_quote.h"
void Disc_quote::debug() const {
	cout << "data members: \n";
	cout << "\tbookNo: " << this->isbn() << "\tprice: " << price
		<< "\tmin_qty" << quantity << "\tdiscount" << discount << endl;
}