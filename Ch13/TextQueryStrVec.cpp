#pragma once
#include "stdafx.h"
#include "TextQueryStrVec.h"
#include <sstream>
#include <algorithm>
#include <iterator>
using std::back_inserter;
using std::remove_copy_if;
using std::istringstream;
using std::endl;

TextQuery::TextQuery(ifstream &inputFile) : text(new StrVec){
	string line, word;
	for (LineNum lineNum = 0; getline(inputFile, line); ++lineNum) {
		text->push_back(line);
		istringstream wordStream(line);
		for (string /*text = "", */word = ""; wordStream >> word; word.clear()) {
			//remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			auto &lines = queryList[word];
			if (!lines) lines.reset(new set<LineNum>);
			lines->insert(lineNum);
		}
	}
}

QueryResult TextQuery::query(const string &word) const {
	static shared_ptr<set<LineNum>> nodata(new set<LineNum>);
	auto found = queryList.find(word);
	if (found == queryList.end())
		return QueryResult(word, nodata, text);
	else
		return QueryResult(word, found->second, text);
}
const set<LineNum>::iterator QueryResult::begin() const {
	return lineNums->begin();
}
const set<LineNum>::iterator QueryResult::end() const{
	return lineNums->end();
}
shared_ptr<StrVec> QueryResult::get_file() const{
	return text;//make_shared<vector<string>>(text);
}
ostream& print(ostream& output, const QueryResult& re) {
	auto occur = re.lineNums->size();
	output << "element occurs " << occur << (occur << occur > 0 ? " times" : " time") << endl;
	for (auto it : *re.lineNums) {
		output << "\t(line " << it + 1 << ") " << *((*re.text).begin()+it) << endl;
	}
	return output;
}