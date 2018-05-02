#include<iostream>
#include<vector>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    vector<int> a;
    for (vector<int>::size_type i = 0; i < 10; i++)
        a.push_back(i);
    auto index = a.begin();
    for (int i : a)
    {
        cout << *index << endl;
        ++index;
    }

    vector<int> b;
    for (int i : a)
    {
        b.push_back(i);
    }
    index = b.begin();
    for (int i : a)
    {
        cout << *index << endl;
        ++index;
    }
    return 0;
}
