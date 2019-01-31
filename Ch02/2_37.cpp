#include<iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    // Decltype does not evaluate the expression!
    decltype(a = b) d = a;
    std::cout << a << std::endl;
    return 0;
}
