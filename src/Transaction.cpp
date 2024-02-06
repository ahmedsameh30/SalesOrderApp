#include "Transaction.h"
using namespace std;

Transaction::Transaction()
{
    //ctor
}

void Transaction::make_order()
{
    cout<<"\n-------------------------------------------------------------\n";
    order.create_order();
}
void Transaction::update_order_items_quantity()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t 1- Order more items\n"
        <<"\t 2- Return some items\n";

    cout<<"\t Enter your choice : ";
    int c; cin>>c;
    cout<<"\n\t Enter order id : ";
    string id; cin>>id;
    switch(c){
        case 1 :
            order.ordering_more_items(id);
            break;
        case 2 :
            order.returning_some_items(id);
            break;
        default :
            cout<<"\n\t Invalid !\n";
    }
}
void Transaction::updateStatus()
{
    string id; int c;
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t Enter order id : ";
    cin>>id;

    cout<<"\t Choose status..\n"
        <<"\t 1- new\n"
        <<"\t 2- hold\n"
        <<"\t 3- paid\n"
        <<"\t 4- cancelled\n";
    cin>>c;
    order.update_status(id,c);
}
void Transaction::pay_order()
{
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t Enter order id : ";
    string id; cin>>id;

    cout<<"\n\t There is still an amount of "<<order.getTotal(id)<<" pounds to be paid for this order\n\n";

    cout<<"\t Enter the amount paid : ";
    double amount; cin>>amount;

    Payment payment(amount);

    order.update_status_after_paid(id,payment.pay());
}
void Transaction::display()
{
    order.display_orders_details();
}
Transaction::~Transaction()
{
    //dtor
}
