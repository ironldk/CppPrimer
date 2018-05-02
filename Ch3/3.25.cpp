#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto beg = scores.begin();
    while (cin >> grade)
    {
        *(beg + grade/10) += 1;
    }
    for (unsigned i : scores)
    {
        cout << i << " ";
    }
    return 0;
}
