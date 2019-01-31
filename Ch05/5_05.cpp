#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main() {
	int grade = 0;
	string letterGrade = "";
	vector<string> score = { "F", "D", "C", "B", "A", "A++" };

	cout << "Input grade: ";
	cin >> grade;
	if (grade < 0 || grade > 100) {
		cout << "Wrong input!";
		return 0;
	}

	if (grade < 60) {
		letterGrade = score[0];
	}
	else {
		letterGrade = score[(grade - 50) / 10];
		if (grade != 100) {
			if (grade % 10 > 7) {
				letterGrade += "+";
			}
			else {
				if (grade % 10 < 3) {
					letterGrade += "-";
				}
			}
		}
		
	}
	cout << "Score is: " << letterGrade;
	return 0;
}