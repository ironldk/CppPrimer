#include<iostream>
#include "Sales_item.h"
int main()
{
    Sales_item current,last;
    last = current;
    int count = 0;
    while(std::cin >> current)
    {
        if(current.isbn() == last.isbn())
        {
            count++;
        }
        else
        {
            std::cout << count << " transactions occur for ISBN number: " << last.isbn() << std::endl;
            count = 1;
            last = current;
        }
    }
    std::cout << count << " transactions occur for ISBN number: " << last.isbn() << std::endl;
    return 0;
}
