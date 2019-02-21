#pragma once
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
#include <vector>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::vector;
int main() {
	Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);
	Bulk_quote a;
	vector<shared_ptr<Quote>> qvec;
	qvec.push_back(make_shared<Quote>("textbook", 10.60));
	qvec.push_back(make_shared<Bulk_quote>("textbook", 10.60, 10, 0.3));
	qvec.push_back(make_shared<Bulk_quote>());
	for (auto p : qvec) {
		cout << p->net_price(15) << endl;
	}
	return 0;
}