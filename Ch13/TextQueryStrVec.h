#pragma once
#include "StrVec.h"
#include <fstream>
#include <string>
#include <memory>
#include <map>
#include <set>
using std::ifstream;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
using std::ostream;
using LineNum = size_t;
class QueryResult;
class TextQuery {
public:
	TextQuery(ifstream &inputFile);
	QueryResult query(const string &word) const;
private:
	shared_ptr<StrVec> text;
	map<string, shared_ptr<set<LineNum>>> queryList;
};

class QueryResult {
	friend ostream &print(ostream &, const QueryResult &);
public:
	QueryResult(string w, shared_ptr<set<LineNum>> l,
		shared_ptr<StrVec> t) : word(w), lineNums(l), text(t) {};
	const set<LineNum>::iterator begin() const;
	const set<LineNum>::iterator end() const;
	shared_ptr<StrVec> get_file() const;
private:
	string word;
	shared_ptr<set<LineNum>> lineNums;
	shared_ptr<StrVec> text;
};

ostream &print(ostream &, const QueryResult &);