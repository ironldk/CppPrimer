#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
#define uint unsigned int

int main()
{
    vector<string> text;
    string temp;
    while (getline(cin, temp))
    {
        text.push_back(temp);
    }
// print each line in text up to the first blank line
    int flag = 0;
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (it->empty())
        {
            flag = 1;
        }
        if (flag == 0)
        {
            for (auto iter = it->begin(); iter != it->end(); iter++)
            {
                *iter = toupper(*iter);
            }
        }
        cout << *it << endl;
    }
    return 0;
}
