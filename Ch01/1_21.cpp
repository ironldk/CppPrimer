#include<iostream>
#include"Sales_item.h"
int main()
{
    Sales_item a,b;
    std::cout << "Enter first item: ";
    std::cin >> a;
    std::cout << "Enter second item: ";
    std::cin >> b;
    std::cout << a+b;
    return 0;
}
