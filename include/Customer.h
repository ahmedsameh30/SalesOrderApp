#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<string>
using namespace std;

class Customer
{
    protected :
        string id;
        string phone;
        string email;
    public :
        Customer();
        virtual void add_customer() = 0;
        virtual void update_customer() = 0;
        virtual bool search_customer(string) = 0;
        virtual void delete_customer() = 0;
        virtual int total_number_of_customers() = 0;
        virtual void display() = 0;
        virtual ~Customer();

    private:
};

#endif // CUSTOMER_H
