#include<iostream>
#include<vector>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    int a[10];
    unsigned j = 0;
    for (int i : a)
    {
        a[j] = j;
        cout << a[j] << endl;
        j++;
    }
    j = 0;
    int b[10];
    for (int i : b)
    {
        b[j] = a[j];
        cout << b[j] << endl;
        j++;
    }
    return 0;
}
