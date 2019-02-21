#pragma once
#include "Disc_quote.h"
class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	using Disc_quote::Disc_quote;
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote &) = default;
	Bulk_quote(Bulk_quote &&) = default;
	Bulk_quote& operator=(const Bulk_quote &) = default;
	Bulk_quote& operator=(Bulk_quote &&) = default;
	//Bulk_quote(const string& book, double p, size_t qty, double disc) :
	//	Disc_quote(book, p, qty, disc) {
	//	cout << "Bulk_quote(const string &, double, size_t, double)" << endl;
	//}
	//Bulk_quote() {
	//	cout << "Bulk_quote()" << endl;
	//}
	//Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) {
	//	cout << "Bulk_quote(const Bulk_quote &)" << endl;
	//}
	//Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs)) {
	//	cout << "Bulk_quote(Bulk_quote &&)" << endl;
	//}
	//Bulk_quote& operator=(const Bulk_quote &rhs) {
	//	Disc_quote::operator=(rhs);
	//	cout << "Bulk_quote& operator=(const Bulk_quote &)" << endl;
	//	return *this;
	//}
	//Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
	//	Disc_quote::operator=(std::move(rhs));
	//	cout << "Bulk_quote& operator=(Bulk_quote &&)" << endl;
	//	return *this;
	//}
	Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
};