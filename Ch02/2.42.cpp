#include <iostream>
#include <string>
#include "Sales_data.h"


int main() {

    int n = 0;
    std::cout << "Input item numbers of raw data: ";
    std::cin >> n;
    std::cout << std::endl;
    Sales_data trans[n];
    double price;
    int continueInput = 1;
    int i = 0;
    do {
        std::cout << "Input trans ISBN, copies sold and price per copy: ";
        std::cin >> trans[i].bookNo >> trans[i].copies_sold >> price;
        trans[i].revenue = trans[i].copies_sold * price;
        for (int j = 0; j < i; j++) {
            if (trans[i].bookNo == trans[j].bookNo) {
                trans[j].revenue += trans[i].revenue;
                trans[j].copies_sold += trans[i].copies_sold;
                i--;
                break;
            }

        }
        i++;

        std::cout << std::endl;
        do {
            std::cout << "Continue input?(1 for yes and 0 for no): ";
            std::cin >> continueInput;
            switch (continueInput) {
                case 1: break;
                case 0: break;
                default: std::cout << std::endl << "Invalid!";
            }
            std::cout << std::endl;
        } while ((continueInput != 1) && (continueInput != 0));

    } while (continueInput == 1);

    for (int j = 0; j < i; j++) {
        double aver = trans[j].revenue / trans[j].copies_sold;
        std::cout << trans[j].bookNo << " " << trans[j].copies_sold << " "
                << trans[j].revenue << " " << aver << std::endl;
    }

    return 0;
}