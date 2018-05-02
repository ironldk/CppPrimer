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
    string line;
    string bigline;
    cout << "input line: ";
    // read input a line at a time and discard blank lines
    while(getline(cin, line))
    {

        cout << endl;
        bigline += line;
        cout << "input line: ";

    }
    cout << "bigline: " << bigline;

    return 0;
}
