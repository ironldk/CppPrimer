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
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 34, 12};
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        *it *= 2;
        cout << *it << " ";
    }
    return 0;
}
