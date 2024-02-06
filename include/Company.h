#ifndef COMPANY_H
#define COMPANY_H

#include <Customer.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Company : public Customer
{
    private :
        string comp_name;
        string location;

        fstream company;

        char _id[10];
        char _comp_name[30];
        char _phone[13];
        char _email[40];
        char _location[50];
    public :
        Company();
        void add_customer();
        void update_customer();
        bool search_customer(string);
        void delete_customer();
        int total_number_of_customers();
        void display();
        virtual ~Company();

    protected:
};

#endif // COMPANY_H
