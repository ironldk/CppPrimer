#pragma once
#include "Query_base.h"
#include "WordQuery.h"
// interface class to manage the Query_base inheritance hierarchy
class Query {
	// these operators need access to the shared_ptr constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string &s): q(new WordQuery(s)) {
		//cout << "Query(const string &)" << endl;
	}; // builds a new WordQuery
	// interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	string rep() const { /*cout << "Query::rep()" << endl;*/ return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) : q(query) {
		//cout << "Query(shared_ptr<Query_base>)" << endl;
	}
	shared_ptr<Query_base> q;
};
inline ostream & operator<<(ostream &os, const Query &query) {
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}
Query operator~(const Query &);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);