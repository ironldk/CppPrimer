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
	while (true) {
		cout << "Input grade: ";
		cin >> grade;
		if (grade < 0 || grade > 100) {
			cout << "Wrong input!";
			return 0;
		}

		letterGrade = grade < 60 ? score[0] : score[(grade - 50) / 10];
		letterGrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";

		cout << "Score is: " << letterGrade << endl;
	}
	return 0;
}