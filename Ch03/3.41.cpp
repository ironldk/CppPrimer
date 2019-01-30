#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> vec(begin(arr), end(arr));
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
