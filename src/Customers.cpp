#include "Customers.h"
#include<iostream>
using namespace std;

Customers::Customers():counter(0),customer(nullptr)
{
    //ctor
}
void Customers::handle_pointer()
{
    delete customer;
    customer = nullptr;
}
void Customers::add_customer()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t What customer type do you want to add ?\n"
        <<"\t 1- Person\n"
        <<"\t 2- Company\n";
    cout<<"\n\t Enter your choice : "; int c; cin>>c;
    switch(c)
    {
        case 1 :
            customer = new Person();
            customer->add_customer();
            handle_pointer();
            break;
        case 2 :
            customer = new Company();
            customer->add_customer();
            handle_pointer();
            break;
        default :
            cout<<"\t Invalid choice\n";
    }
}
void Customers::update_customer()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\n\t What customer type do you want to update ?\n"
        <<"\t 1- Person\n"
        <<"\t 2- Company\n";
    cout<<"\n\t Enter your choice : "; int c; cin>>c;
    switch(c)
    {
        case 1 :
            customer = new Person();
            customer->update_customer();
            handle_pointer();
            break;
        case 2 :
            customer = new Company();
            customer->update_customer();
            handle_pointer();
            break;
        default :
            cout<<"\t Invalid choice\n";
    }
}
void Customers::delete_customer()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\n\t What customer type do you want to delete ?\n"
        <<"\t 1- Person\n"
        <<"\t 2- Company\n";
    cout<<"\n\t Enter your choice : "; int c; cin>>c;
    switch(c)
    {
        case 1 :
            customer = new Person();
            customer->delete_customer();
            handle_pointer();
            break;
        case 2 :
            customer = new Company();
            customer->delete_customer();
            handle_pointer();
            break;
        default :
            cout<<"\t Invalid choice\n";
    }
}
int Customers::total_number_of_customers()
{
    int c = 0,totalNum = 0;
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t What customer type do you want to know its total number ?\n"
        <<"\t 1- Person\n"
        <<"\t 2- Company\n"
        <<"\t 3- Both\n";
    cout<<"\n\t Enter your choice : "; cin>>c;
    switch(c)
    {
        case 1 :
            customer = new Person();
            totalNum = customer->total_number_of_customers();
            handle_pointer();
            break;
        case 2 :
            customer = new Company();
            totalNum = customer->total_number_of_customers();
            handle_pointer();
            break;
        case 3 :
            customer = new Person();
            totalNum += customer->total_number_of_customers();
            handle_pointer();
            customer = new Company();
            totalNum += customer->total_number_of_customers();
            handle_pointer();
            break;
        default :
            cout<<"\t Invalid choice\n";
    }
    return totalNum;
}
void Customers::display()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t what customer type do you want to display ?\n";
    cout<<"\t [1] persons\n"
        <<"\t [2] companies\n";
    cout<<"\t Enter your choice : "; int x; cin>>x;
    switch(x){
        case 1 :
            customer = new Person();
            customer->display();
            break;
        case 2 :
            customer = new Company();
            customer->display();
            break;
        default :
            cout<<"\t Invalid choice\n";
    }
}
Customers::~Customers()
{
    if(customer != nullptr){
        handle_pointer();
    }
}
