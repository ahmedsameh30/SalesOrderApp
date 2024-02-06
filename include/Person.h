#ifndef PERSON_H
#define PERSON_H

#include <Customer.h>
#include<string>
#include<fstream>
using namespace std;

class Person : public Customer
{
    private :
        string fullname;
        string billing_address;

        fstream person;

        // for reading from file..
        char _id[10];
        char _fullname[50];
        char _phone[13];
        char _email[40];
        char _billing_address[40];
    public:
        Person();
        void add_customer();
        void update_customer();
        bool search_customer(string);
        void delete_customer();
        int total_number_of_customers();
        void display();
        virtual ~Person();

    protected:
};

#endif // PERSON_H
