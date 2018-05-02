#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string s1 = "i love programming";
    string s2 = "i love learning";
    if (s1 < s2)
        cout << "s1 is smaller" << endl;
    else if(s1 == s2)
        cout << "same" << endl;
    else
        cout << "s2 is smaller";
    return 0;
}
