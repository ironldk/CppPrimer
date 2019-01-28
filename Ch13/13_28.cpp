//Exercise 13.28: Given the following classes, implement a default constructor
//and the necessary copy - control members
#include "stdafx.h"
#include <string>
#include <memory>
using std::string;
class TreeNode {
public:
	TreeNode() :value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &init) :
		value(init.value), count(init.count), left(init.left), right(init.right) {
		++*count;
	}
	TreeNode &operator=(const TreeNode &);
	~TreeNode() {
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
	}
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
class BinStrTree {
public:
	BinStrTree():root(new TreeNode()){}
	BinStrTree(const BinStrTree &init):root(new TreeNode(*init.root)){}
	BinStrTree &operator=(const BinStrTree &rhs) {
		auto new_root = new TreeNode(*rhs.root);
		delete root;
		root = new_root;
		return *this;
	}
	~BinStrTree() { delete root; }
private:
	TreeNode * root;
};
TreeNode &TreeNode::operator=(const TreeNode &rhs) {
	value = rhs.value;
	++*rhs.count;
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}