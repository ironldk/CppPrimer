#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main()
{
    vector<string> svec;
    string temp;

    while (cin >> temp)
    {
        svec.push_back(temp);
    }
    for (decltype(svec.size()) i = 0; i < svec.size(); i++)
    {
        for (decltype(svec[i].size()) j = 0; j < svec[i].size(); j++)
        {
            svec[i][j] = toupper(svec[i][j]);
        }
        cout << svec[i] << "\t";
        if (i % 8 == 7)
            cout << endl;
    }

    return 0;
}
