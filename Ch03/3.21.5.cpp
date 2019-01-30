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
    vector<int> vec;
    int temp;
    while (cin >> temp)
    {
        vec.push_back(temp);
    }

    // print the sum of each pair of adjacent elements
    for (auto it = vec.cbegin(); it != vec.cend() - 1; it++)
    {
        cout << *it + *(it + 1) << " ";
    }
    cout << endl;
    // prints the sum of the first and last elements,
    // followed by the sum of the second and second-tolast,
    // and so on
    auto iter = vec.cend() - 1;
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
    {
        cout << *it + *iter << " ";
        iter--;
    }

}
