#pragma once
#include "..\\Ch12\\TextQuery.h"
#include <iostream>
using std::cout;
using std::endl;
// abstract class acts as a base class for concrete query types; all members are private
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::LineNum; // used in the eval functions
	virtual ~Query_base() = default;
private:
	// eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep is a string representation of the query
	virtual string rep() const = 0;
};