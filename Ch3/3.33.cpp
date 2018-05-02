#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    // count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
    unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
    unsigned grade;
    for (int i = 0; i < 11; i++)
    {
        cout << scores[i] << " ";
    }

    cout << endl;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade/10]; // increment the counter for the current cluster
    }
    return 0;
}
