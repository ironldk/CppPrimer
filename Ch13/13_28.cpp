//Exercise 13.28: Given the following classes, implement a default constructor
//and the necessary copy - control members
#include "stdafx.h"
#include <string>
using std::string;
class TreeNode {
public:
	TreeNode();
	TreeNode(const TreeNode &rhs):
		value(rhs.value), count(rhs.count), left(rhs.left), right(right) { ++*count; }
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
class BinStrTree {
private:
	TreeNode * root;
};