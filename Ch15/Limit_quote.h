#pragma once
#include "Disc_quote.h"
class Limit_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	using Disc_quote::Disc_quote;
	Limit_quote() = default;
	Limit_quote(const Limit_quote &) = default;
	Limit_quote(Limit_quote &&) = default;
	Limit_quote& operator=(const Limit_quote &) = default;
	Limit_quote& operator=(Limit_quote &&) = default;
	//Limit_quote(const std::string& book, double p,
	//	std::size_t qty, double disc) :
	//	Disc_quote(book, p, qty, disc) { }
	Limit_quote* clone() const & { return new Limit_quote(*this); }
	Limit_quote* clone() && { return new Limit_quote(std::move(*this)); }
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
};