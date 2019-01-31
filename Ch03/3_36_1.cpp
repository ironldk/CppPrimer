#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;
int main()
{
    vector<int> a1 = {0, 2, 4, 6, 8};
    //vector<int> a2 = {0, 1, 2, 3, 4, 5};
    //vector<int> a2 = {0, 1, 2, 3, 4};
    vector<int> a2 = {0, 2, 4, 6, 8};

    if ((a1.end() - a1.begin()) == (a2.end() - a2.begin()))
    {
        bool same = true;
        for (decltype(a1.size()) i = 0; i < a1.size(); i++)
        {
            if (a1[i] != a2[i])
            {
                cout << "Not equal!(same length)" << endl;
                same = false;
                break;
            }
        }
        if (same)
            cout << "Equal!" << endl;
    }
    else
    {
        cout << "Not equal!(different length)" << endl;
    }
    return 0;
}
