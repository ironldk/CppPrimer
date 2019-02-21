#include "Basket.h"
double Basket::total_receipt(ostream &os) const {
	double sum = 0.0; // holds the running total
	// iter refers to the first element in a batch of elements with the same ISBN
	// upper_bound returns an iterator to the element just past the end of that batch
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)) {
		// we know there's at least one element with this key in the Basket
		// print the line item for this book
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl; // print the final overall	total
	return sum;
}
void Basket::add_item(const Quote &sale) {
	items.insert(shared_ptr<Quote>(sale.clone()));
} // copy the given object
void Basket::add_item(Quote &&sale) {
	items.insert(shared_ptr<Quote>(std::move(sale).clone()));
} // move the given object