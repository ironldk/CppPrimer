#include "stdafx.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using std::istringstream;
using std::cout;
using std::endl;
using std::string;
// using namespace std;

istringstream & func(istringstream &);

int main() {
	istringstream in("Hello World!");
	func(in);
	return 0;
}


//istream & func(istream &i) {
//	string temp;
//	while (~i.eof()) {
//		i >> temp;
//		cout << "first temp: " << temp << endl;
//		i >> temp;
//		cout << "second temp:" << temp << endl;
//	}
//	i.clear();
//	return i;
//}


istringstream& func(istringstream &is)
{
	std::string buf;
	while (is >> buf)
		std::cout << buf << std::endl;
	is.clear();
	return is;
}