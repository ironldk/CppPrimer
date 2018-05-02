#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int arr[] = {0, 2, 4, 6, 8};
    int *p = arr;
    for (int i : arr)
    {
        cout << i << " ";
    }
    for (int i : arr)
    {
        *p = 0;
        p++;
    }
    cout << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
