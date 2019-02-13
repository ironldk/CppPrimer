#pragma once
#include "Disc_quote.h"
class Limit_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	Limit_quote() = default;
	Limit_quote(const std::string& book, double p,
		std::size_t qty, double disc) :
		Disc_quote(book, p, qty, disc) { }
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
};