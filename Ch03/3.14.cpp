#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int main()
{
    // read words from the standard input and store them as elements in a vector
    int n;
    vector<int> numbers; // empty vector
    while (cin >> n)
    {
        numbers.push_back(n); // append word to text
    }
    for (decltype(numbers.size()) i = 0; i < numbers.size(); i++)
        cout << numbers[i];
    return 0;
}
