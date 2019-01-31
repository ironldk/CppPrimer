#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main()
{
    int a1[] = {0, 2, 4, 6, 8};
    //int a2[] = {0, 1, 2, 3, 4, 5};
    int a2[] = {0, 1, 2, 3, 4};
    //int a2[] = {0, 2, 4, 6, 8};

    int *p1 = a1;
    int *b1 = begin(a1);
    int *e1 = end(a1);

    int *p2 = a2;
    int *b2 = begin(a2);
    int *e2 = end(a2);

    if ((e1 - b1) == (e2 - b2))
    {
        while (b1 < e1)
        {
            if (*p1 != *p2)
            {
                cout << "Not equal!(same length)" << endl;
                break;
            }
            p1++;
            p2++;
            b1++;
        }
        if (b1 == e1)
            cout << "Equal!" << endl;
    }
    else
    {
        cout << "Not equal!(different length)" << endl;
    }
    return 0;
}
