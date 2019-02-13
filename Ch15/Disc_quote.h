#pragma once
#pragma once
#include "Quote.h"
class Disc_quote : public Quote { // Bulk_quote inherits from Quote
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double p,
		std::size_t qty, double disc) :
		Quote(book, p), quantity(qty), discount(disc) { }
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const = 0;
	void debug() const override;
protected: // minimum purchase for the discount to apply
	std::size_t quantity = 0;
	double discount = 0.0; // fractional discount to apply
};