#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << v1.size() << endl;
    for (decltype(v1.size()) i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << v2.size() << endl;
    for (decltype(v2.size()) i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << v3.size() << endl;
    for (decltype(v3.size()) i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;

    cout << v4.size() << endl;
    for (decltype(v4.size()) i = 0; i < v4.size(); i++)
    {
        cout << v4[i] << " ";
    }
    cout << endl;

    cout << v5.size() << endl;
    for (decltype(v5.size()) i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }
    cout << endl;

    cout << v6.size() << endl;
    for (decltype(v6.size()) i = 0; i < v6.size(); i++)
    {
        cout << v6[i] << " ";
    }
    cout << endl;

    cout << v7.size() << endl;
    for (decltype(v7.size()) i = 0; i < v7.size(); i++)
    {
        cout << v7[i] << " ";
    }
    cout << endl;

    return 0;
}
