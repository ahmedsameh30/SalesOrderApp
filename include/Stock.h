#ifndef STOCK_H
#define STOCK_H

#include<iostream>
#include<fstream>
#include<string>
#include "Product.h"
using namespace std;

class Stock
{
    private :
        Product product;
        fstream stock;

        // for reading from file..
        char _id[10];
        char _name[30];
        char _price[10];
        char _quantity[10];
    public:
        Stock();
        void add_to_stock();
        void update_stock();
        void update_product_quantity_after_order_or_return(string,int,char);
        void delete_product_in_stock();
        int getProductCount();
        int get_product_quantity(string);
        double get_product_price(string);
        bool search_for_product(string);
        void display();
        virtual ~Stock();

    protected:
};

#endif // STOCK_H
