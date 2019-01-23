//Exercise 13.18: Define an Employee class that contains an employee name
//and a unique employee identifier.Give the class a default constructor and a
//constructor that takes a string representing the employee��s name.Each
//constructor should generate a unique ID by incrementing a static data
//member
#include "stdafx.h"
#include <iostream>
#include <string>
using std::string;
class Employee {
public:
	Employee() { identifier = ++unique; }
	Employee(const string &s) { name = s; identifier = ++unique; }
private:
	static int unique;
	string name;
	int identifier;
};
int Employee::unique = 0;
int main() {

}