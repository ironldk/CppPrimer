#pragma once
#include <iostream>
#include <string>
// use delegating constructors, added a statement to the body of each of the
// constructors that prints a message whether it is executed
class Sales_data {
	friend std::istream& operator>>(std::istream& is, Sales_data& item);
	friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);
	friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
public:
	Sales_data(const std::string& s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(n * p){
		std::cout << "Sales_data(const std::string&, unsigned, double)"
			<< std::endl;
	}
	Sales_data() : Sales_data("", 0, 0.0f){
		std::cout << "Sales_data()" << std::endl;
	}
	Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f){
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}
	Sales_data(std::istream& is);
	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator=(const std::string&);
	operator std::string() const { return bookNo; }
	operator double() const { return revenue; }
private:
	inline double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
inline double Sales_data::avg_price() const{
	return units_sold ? revenue / units_sold : 0;
}
// declarations for nonmember parts of the Sales_data interface.
std::istream& operator>>(std::istream& is, Sales_data& item);
std::ostream& operator<<(std::ostream& os, const Sales_data& item);
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);