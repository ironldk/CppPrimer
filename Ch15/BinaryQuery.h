#pragma once
#include "Query_base.h"
#include "Query.h"
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, string	s) :
		lhs(l), rhs(r), opSym(s) {
		//cout << "BinaryQuery(const Query &, const Query &, string)" << endl;
	}
	// abstract class: BinaryQuery doesn't define eval
	string rep() const {
		//cout << "BinaryQuery::rep()" << endl;
		return "(" + lhs.rep() + " " + opSym + " "	+ rhs.rep() + ")";
	}
	Query lhs, rhs; // right- and left-hand operands
	string opSym; // name of the operator
};