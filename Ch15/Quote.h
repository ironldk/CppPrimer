#pragma once
#include <string>
#include <iostream>
using std::ostream;
using std::string;
using std::cout;
using std::endl;
class Quote {
public:
	Quote() = default;
	Quote(const Quote &) = default;
	Quote(Quote &&) = default;
	Quote& operator=(const Quote &) = default;
	Quote& operator=(Quote &&) = default;
	virtual ~Quote() = default;
	Quote(const string &book, double sales_price) :
		bookNo(book), price(sales_price) {
		cout << "Quote(const string &, double)" << endl;
	}
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
	//Quote() : bookNo(), price(0) {
	//	cout << "Quote()" << endl;
	//}
	//Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {
	//	cout << "Quote(const Quote &)" << endl;
	//} // memberwise copy
	//Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
	//	cout << "Quote(Quote &&)" << endl;
	//} // memberwise move
	//Quote& operator=(const Quote &rhs) {
	//	cout << "Quote& operator=(const Quote &)" << endl;
	//	bookNo = rhs.bookNo;
	//	price = rhs.price;
	//	return *this;
	//} // copy assign
	//Quote& operator=(Quote &&rhs) noexcept {
	//	cout << "Quote& operator=(Quote &&)" << endl;
	//	bookNo = std::move(rhs.bookNo);
	//	price = std::move(rhs.price);
	//	return *this;
	//}; // move assign
	//virtual ~Quote() {
	//	cout << "~Quote()" << endl;
	//}; // dynamic binding for the destructor
	std::string isbn() const { return bookNo; }
	// returns the total sales price for the specified number of items
	// derived classes will override and apply different discount algorithms
	virtual double net_price(std::size_t n) const;
	virtual void debug() const;
private:
	std::string bookNo; // ISBN number of this item
protected:
	double price = 0.0; // normal, undiscounted price
};