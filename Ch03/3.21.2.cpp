#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> svec;
    string temp;
    while (cin >> temp)
    {
        svec.push_back(temp);
    }

    unsigned int counter = 0;
    for (auto it = svec.begin(); it != svec.end(); it++)
    {
        for (auto iter = it->begin(); iter != it->end(); iter++)
        {
            *iter = toupper(*iter);
        }
        cout << *it << " ";

        if (counter%8 == 7)
            cout << endl;
        counter++;
    }


    return 0;
}
