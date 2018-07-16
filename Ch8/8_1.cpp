#include "stdafx.h"
#include<iostream>
#include<string>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
// using namespace std;

istream & func(istream &i);

int main() {
	func(cin);
	return 0;
}


istream & func(istream &i) {
	string temp;
	while (~i.eof()) {
		i >> temp;
		cout << "first temp: " << temp << endl;
		i >> temp;
		cout << "second temp:" << temp << endl;
	}
	i.clear();
	return i;
}


//istream& func(istream &is)
//{
//	std::string buf;
//	while (is >> buf)
//		std::cout << buf << std::endl;
//	is.clear();
//	return is;
//}