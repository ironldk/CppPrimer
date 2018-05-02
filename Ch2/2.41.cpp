#include<iostream>
#include<string>

int main()
{
    struct Sales_data
    {
        std::string bookNo;
        unsigned int copies_sold = 0;
        double revenue = 0.0;
    };
    Sales_data trans1, trans2, trans3;
    double price;

    std::cout << "Input trans1 ISBN, copies sold and price per copy: ";
    std::cin >> trans1.bookNo >> trans1.copies_sold >> price;
    trans1.revenue = trans1.copies_sold * price;

    std::cout << "Input trans2 ISBN, copies sold and price per copy: ";
    std::cin >> trans2.bookNo >> trans2.copies_sold >> price;
    trans2.revenue = trans2.copies_sold * price;

    std::cout << "Input trans3 ISBN, copies sold and price per copy: ";
    std::cin >> trans3.bookNo >> trans3.copies_sold >> price;
    trans3.revenue = trans3.copies_sold * price;

    if ((trans1.bookNo == trans2.bookNo) && (trans1.bookNo == trans3.bookNo))
    {
        unsigned int total_sold = trans1.copies_sold
                                  + trans2.copies_sold + trans3.copies_sold;
        std::cout << trans1.bookNo << " " << total_sold << " ";
        double total_revenue = trans1.revenue + trans2.revenue + trans3.revenue;
        std::cout << total_revenue << " ";
        if (total_sold != 0)
        {
            double average_price = total_revenue / total_sold;
            std::cout << average_price;
        }
        else
        {
            std::cout << "(no sale)";
        }
        return 0;

    }
    else
    {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }

    return 0;
}
