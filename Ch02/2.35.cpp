#include<iostream>

int main()
{
    const int i = 42;
    auto j = i;
    j = 1; // determine whether j is plain int, error means no.
    const auto &k = i;
    //k = 1; // determine whether k is reference to const int, error means yes.
    auto *p = &i;
    //*p = 1; //determine whether p is pointer to const int, error means yes.
    const auto j2 = i, &k2 = i;
    //j2 = 1; // determine whether j2 is const int, error means yes.
    //k2 = 1; // determine whether k2 is reference to const int, error means yes.
    return 0;
}
