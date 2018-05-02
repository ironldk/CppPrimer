#include<iostream>
#include<vector>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;
string sa[10];
int ia[10];
int main()
{
    for (int i = 0; i < 10; i++)
        cout << "sa: " << sa[i] << "\tia:" << ia[i] << endl;
    string sa2[10];
    int ia2[10];
    for (int i = 0; i < 10; i++)
        cout << "sa2: " << sa2[i] << "\tia2:" << ia2[i] << endl;
    return 0;
}
