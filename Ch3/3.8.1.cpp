#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string str;
    getline(cin,str);;
    decltype(str.size()) i = 0;
    while (i < str.size())
    {
        str[i] = 'X';
        i++;
    }
    cout << str;
    return 0;
}
