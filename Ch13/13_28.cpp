//Exercise 13.28: Given the following classes, implement a default constructor
//and the necessary copy - control members
#include "stdafx.h"
#include <string>
using std::string;
class TreeNode {
public:
	TreeNode();
	TreeNode()
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};
class BinStrTree {
private:
	TreeNode * root;
};