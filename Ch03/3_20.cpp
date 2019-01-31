#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main()
{
    vector<int> vec;
    int temp;

    while (cin >> temp)
    {
        vec.push_back(temp);
    }
    for (decltype(vec.size()) i = 0; i < vec.size(); i++)
    {
        cout << vec[i] + vec[vec.size() - i - 1] << "\t";
    }

    return 0;
}
