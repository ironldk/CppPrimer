//Exercise 9.52: Use a stack to process parenthesized expressions.When
//you see an open parenthesis, note that it was seen.When you see a close
//parenthesis after an open parenthesis, pop elements down to and including
//the open parenthesis off the stack.push a value onto the stack to
//indicate that a parenthesized expression was replaced
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using std::string;
using std::stack;
using std::cout;
using std::endl;

int main()
{
	string str = "2*(3+4)=14";
	stack<char> stk;
	auto i = str.begin();
	for (auto iter = str.begin(); iter != str.end(); ++iter) {
		stk.push(*iter);
		if (*iter == '(') i = iter;
		if (*iter == ')') {
			for (auto ip = iter; ip >= i; --ip)
				stk.pop();
			stk.push('e');
		}
	}
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}