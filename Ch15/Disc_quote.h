#pragma once
#pragma once
#include "Quote.h"
using std::size_t;
class Disc_quote : public Quote { // Disc_quote inherits from Quote
public:
	Disc_quote() = default;
	Disc_quote(const Disc_quote &) = default;
	Disc_quote(Disc_quote &&) = default;
	Disc_quote& operator=(const Disc_quote &) = default;
	Disc_quote& operator=(Disc_quote &&) = default;
	Disc_quote(const string& book, double p,
		std::size_t qty, double disc) :
		Quote(book, p), quantity(qty), discount(disc) { }
	//Disc_quote(const Disc_quote &rhs) : Quote(rhs),
	//	quantity(rhs.quantity), discount(rhs.discount) { }
	//Disc_quote(Disc_quote &&rhs) noexcept : Quote(std::move(rhs)),
	//	quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) { }
	//Disc_quote& operator=(const Disc_quote &rhs) {
	//	Quote::operator=(rhs);
	//	quantity = rhs.quantity;
	//	discount = rhs.discount;
	//	return *this;
	//}
	//Disc_quote& operator=(Disc_quote &&rhs) noexcept {
	//	Quote::operator=(std::move(rhs));
	//	quantity = std::move(rhs.quantity);
	//	discount = std::move(rhs.discount);
	//	return *this;
	//}
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(size_t) const = 0;
	void debug() const override;
protected: // minimum purchase for the discount to apply
	size_t quantity = 0;
	double discount = 0.0; // fractional discount to apply
};