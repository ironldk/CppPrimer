#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string str;
    getline(cin, str);
    decltype(str.size()) i = 0;
    for (i = 0; i < str.size(); i++)
    {
        str[i] = 'X';
    }
    cout << str;
    return 0;
}
