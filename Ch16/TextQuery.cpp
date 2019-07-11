#include "TextQuery.h"
#include <sstream>
#include <algorithm>
#include <iterator>
//#include <memory>
using std::back_inserter;
using std::remove_copy_if;
using std::istringstream;
//using std::make_shared;
using std::endl;

TextQuery::TextQuery(ifstream &inputFile):
	text(new vector<string>, DebugDelete()){
	string line, word;
	for (LineNum lineNum = 0; getline(inputFile, line); ++lineNum) {
		text->push_back(line);
		istringstream wordStream(line);
		for (string /*text = "", */word = ""; wordStream >> word; word.clear()) {
			//remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			auto &lines = queryList[word];
			if (!lines) lines.reset(new set<LineNum>, DebugDelete());
			lines->insert(lineNum);
		}
	}
}

QueryResult TextQuery::query(const string &word) const {
	static shared_ptr<set<LineNum>> nodata(new set<LineNum>, DebugDelete());
	auto found = queryList.find(word);
	if (found == queryList.end())
		return QueryResult(word, nodata, text);
	else
		return QueryResult(word, found->second, text);
}
const set<TextQuery::LineNum>::iterator QueryResult::begin() const {
	return lineNums->begin();
}
const set<TextQuery::LineNum>::iterator QueryResult::end() const{
	return lineNums->end();
}
shared_ptr<vector<string>> QueryResult::get_file() const{
	return text;//make_shared<vector<string>>(text);
}
ostream& print(ostream& output, const QueryResult& re) {
	auto occur = re.lineNums->size();
	output << "element occurs " << occur << (occur << occur > 0 ? " times" : " time") << endl;
	for (auto it : *re.lineNums) {
		output << "\t(line " << it + 1 << ") " << (*re.text)[it] << endl;
	}
	return output;
}