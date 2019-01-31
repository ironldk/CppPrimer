/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
// Note: #include and using declarations must be added to compile this code

int main()
{
    string line1, line2;
    // read input a line at a time and discard blank lines
    cout << "input line1: ";
    getline(cin, line1);
    cout << endl;
    cout << "input line2: ";
    getline(cin, line2);
    cout << endl;
    if (line1.size() == line2.size())
    {
        cout << "line1 line2 has the same length" << endl;
    }
    else if (line1.size() > line2.size())
    {
        cout << "line1 is longer" << endl;
    }
    else
    {
        cout << "line2 is longer" << endl;
    }
    return 0;
}
