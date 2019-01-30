#include "stdafx.h"
#include "..\..\CppPrimerRepo\Ch13\StrVec.h"
#include <iostream>

int main() {
	StrVec vec_list{ "hello", "world", "pezy" };
	const StrVec const_vec_list = { "hello", "world", "pezy" };
	if (vec_list == const_vec_list)
		for (const auto& str : const_vec_list) std::cout << str << " ";
	std::cout << std::endl;

	// Test operator<
	const StrVec const_vec_list_small = { "hello", "pezy", "ok" };
	std::cout << (const_vec_list_small < const_vec_list) << std::endl;
	return 0;
}