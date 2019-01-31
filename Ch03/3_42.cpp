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


    vector<int> vec = {0, 1, 2, 3, 4, 5};
    int l = vec.size();
    int arr[l];
    for (int i = 0; i < l; i++)
        arr[i] = vec[i];
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}

