#include "stdafx.h"
#include "Sales_data.h"

// constructor
Sales_data::Sales_data(std::istream& is) : Sales_data()
{
	std::cout << "Sales_data(istream &is)" << std::endl;
	is >> *this;
}

// member functions.
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator=(const std::string &isbn) {
	*this = Sales_data(isbn);
	return *this;
}

// friend functions
std::istream& operator>>(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else {
		std::cout << "error input" << std::endl;
		item = Sales_data();
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}