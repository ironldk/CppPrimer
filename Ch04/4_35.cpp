#include "stdafx.h"
#include<string>
#include<iostream>
using std::string;
int main() {
	int fuck = 3;
	int *ip = &fuck;
	char *pc = reinterpret_cast<char*>(ip);
	string str(pc);
	std::cout << str << std::endl;
	return 0;
}