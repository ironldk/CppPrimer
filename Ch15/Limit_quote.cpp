#include "Limit_quote.h"
// if the specified number of items are purchased, use the discounted price
double Limit_quote::net_price(size_t cnt) const {
	if (cnt > quantity)
		return (quantity * (1 - discount) + cnt - quantity) * price;
	else
		return cnt * price * (1 - discount);
}