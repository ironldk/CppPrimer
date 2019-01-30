//Write a function that takes a forward_list<string> and
//two additional string arguments.The function should find the first string
//and insert the second immediately following the first.If the first string is
//not found, then insert the second string at the end of the list.
#include"stdafx.h"
#include<iostream>
#include<forward_list>
#include<string>
using std::string;
using std::forward_list;
using std::cout;
using std::endl;
using std::distance;

void find_and_insert(forward_list<string>& str_flst, const string& to_find, const string& to_insert) {
	auto size = distance(str_flst.begin(), str_flst.end());
	auto prev = str_flst.before_begin();
	for (auto curr = str_flst.begin(); curr != str_flst.end(); prev = curr++) {
		if (*curr == to_find) {
			curr = str_flst.insert_after(curr, to_insert);
			prev = curr++;
		}
	}
	if (size == distance(str_flst.begin(), str_flst.end())) str_flst.insert_after(prev, to_insert);
}

int main() {
	forward_list<string> flst = { "0","1","2","3","4","5","6","7","8","9" };
	for (auto i : flst) {
		cout << i << endl;
	}
	find_and_insert(flst, "00", "asdij");
	for (auto i : flst) {
		cout << i << endl;
	}
	return 0;
}