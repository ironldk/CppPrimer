#pragma once
#include "BinaryQuery.h"
class AndQuery : public BinaryQuery {
	friend Query operator& (const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {
		//cout << "AndQuery(const Query&, const Query&)" << endl;
	}
	// concrete class: AndQuery inherits rep and defines the remaining pure virtual
	QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}