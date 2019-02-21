#pragma once
#include "Query_base.h"
class WordQuery : public Query_base {
	friend class Query; // Query uses the WordQuery constructor
	WordQuery(const string &s) : query_word(s) {
		//cout << "WordQuery(const string &)" << endl;
	}
	// concrete class: WordQuery defines all inherited pure virtual functions
	QueryResult eval(const TextQuery &t) const {
		return t.query(query_word);
	}
	string rep() const { /*cout << "WordQuery::rep()" << endl;*/ return query_word; }
	string query_word; // word for which to search
};