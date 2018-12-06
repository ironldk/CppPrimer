//Exercise 9.51: Write a class that has three unsigned members
//representing year, month, and day.Write a constructor that takes a string
//representing a date.Your constructor should handle a variety of date
//formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

vector<string> m = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

class da {
public:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	da(const string &d) {
		bool found_it = false;
		string::size_type cp = 0;
		string temp;
		for (auto iter = m.begin(); iter < m.end(); ++iter) {
			if (d.find_first_of(*iter) != string::npos) {
				found_it = true;
				month = iter - m.begin() + 1;
				break;
			}
		}
		if (found_it == false) {
			month = stoi(d, &cp);
		}
		day = stoi(temp = d.substr(d.find_first_of("0123456789", cp)), &cp);
		/*d.find_first_of("0123456789", cp);
		d.substr(d.find_first_of("0123456789", cp));
		stoi(d.substr(d.find_first_of("0123456789", cp)), &cp);*/
		year = stoi(temp.substr(temp.find_first_of("0123456789", cp)));
	}
};

int main()
{
	da d1("January 1, 1900"), d2("1/1/1900"), d3("Jan 1, 1900");
	std::cout << d1.year << " " << d1.month << " " << d1.day << std::endl;
	std::cout << d2.year << " " << d2.month << " " << d2.day << std::endl;
	std::cout << d3.year << " " << d3.month << " " << d3.day << std::endl;
	return 0;
}