#include "AndQuery.h"
#include <algorithm>
#include <iterator>
//#include "..\\Ch12\\TextQuery.h"
using std::set_intersection;
using std::inserter;
using std::make_shared;
// returns the intersection of its operands' result sets
QueryResult AndQuery::eval(const TextQuery& text) const {
	// virtual calls through the Query operands to get result sets for the operands
	auto left = lhs.eval(text), right = rhs.eval(text);
	// set to hold the intersection of left and right
	auto ret_lines = make_shared<set<line_no>>();
	// writes the intersection of two ranges to a destination iterator
	// destination iterator in this call adds elements to ret
	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}