#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string s;
    getline(cin, s);
    for (auto c : s)
        if (!ispunct(c))
        cout << c;
    return 0;
}
