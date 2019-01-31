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
    string word;
    vector<string> text; // empty vector
    while (cin >> word)
    {
        text.push_back(word); // append word to text
    }
    for (decltype(text.size()) i = 0; i < text.size(); i++)
        cout << text[i];
    return 0;
}
