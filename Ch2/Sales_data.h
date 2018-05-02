/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sales_data.h
 * Author: irondk
 *
 * Created on July 29, 2017, 11:11 PM
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int copies_sold = 0;
    double revenue = 0.0;
};
#endif /* SALES_DATA_H */