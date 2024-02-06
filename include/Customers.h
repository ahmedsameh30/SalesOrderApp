#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include<iostream>
#include "Customer.h"
#include "Person.h"
#include "Company.h"
using namespace std;

class Customers
{
    private :
        int counter;
        Customer* customer;
    public:
        Customers();
        void add_customer();
        void update_customer();
        void delete_customer();
        int total_number_of_customers();
        void display();

        void handle_pointer();
        virtual ~Customers();

    protected:
};

#endif // CUSTOMERS_H
