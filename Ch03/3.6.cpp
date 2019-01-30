#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string str;
    cin >> str;
    for (auto &rc : str)
    {
        rc = 'X';
    }
    cout << str;
    return 0;
}
