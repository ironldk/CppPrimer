//Exercise 12.16: Compilers don¡¯t always give easy - to - understand error
//messages if we attempt to copy or assign a unique_ptr.Write a program
//that contains these errors to see how your compiler diagnoses them
#include"stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::unique_ptr;

int main() {
	unique_ptr<int> pi(new int(10));
	//unique_ptr<int> p2 = new int(1);
	unique_ptr<int> p3(pi);
	return 0;
}