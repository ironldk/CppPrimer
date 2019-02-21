#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
using std::vector;
using std::ifstream;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
using std::ostream;
class QueryResult;
class TextQuery {
public:
	using LineNum = vector<string>::size_type;
	TextQuery(ifstream &inputFile);
	QueryResult query(const string &word) const;
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<LineNum>>> queryList;
};

class QueryResult {
	friend ostream &print(ostream &, const QueryResult &);
public:
	using LineNum = TextQuery::LineNum;
	QueryResult(string w, shared_ptr<set<LineNum>> l,
		shared_ptr<vector<string>> t) : word(w), lineNums(l), text(t) {};
	const set<LineNum>::iterator begin() const;
	const set<LineNum>::iterator end() const;
	shared_ptr<vector<string>> get_file() const;
private:
	string word;
	shared_ptr<set<LineNum>> lineNums;
	shared_ptr<vector<string>> text;
};

ostream &print(ostream &, const QueryResult &);