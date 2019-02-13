#pragma once
#include "Disc_quote.h"
class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p,
		std::size_t qty, double disc) :
		Disc_quote(book, p, qty, disc) { }
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
};