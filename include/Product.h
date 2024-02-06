#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Product
{
    public:
        string id;
        string name;
        string price;
        string quantity;

        Product();
        virtual ~Product();

    protected:
    private :
};

#endif // PRODUCT_H
