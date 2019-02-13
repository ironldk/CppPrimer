#include "Bulk_quote.h"
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}