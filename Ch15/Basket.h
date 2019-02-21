#pragma once
#include <memory>
#include <ostream>
#include <set>
#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using std::shared_ptr;
using std::ostream;
using std::multiset;
double print_total(ostream &, const Quote &, size_t);
class Basket {
public:
	// Basket uses synthesized default constructor and copy-control members
	void add_item(const Quote &); // copy the given object
	void add_item(Quote &&); // move the given object
	// prints the total price for each book and the overall total for all items in the basket
	double total_receipt(ostream&) const;
private:
	// function to compare shared_ptrs needed by the multiset member
	static bool compare(const shared_ptr<Quote> &lhs,
		const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	// multiset to hold multiple quotes, ordered by the compare member
	multiset<shared_ptr<Quote>, decltype(compare)*>	items{ compare };
};