#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int arr[] = {0, 2, 4, 6, 8};
    int *p1 = arr + 5;
    int *p2 = arr;
    p1 += p2 - p1;
    return 0;
}

