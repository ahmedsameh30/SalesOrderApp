#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<bits/stdc++.h>
#include "Order.h"
#include "Payment.h"
using namespace std;

class Transaction
{
    private :
        Order order;
    public :
        Transaction();
        void make_order();
        void update_order_items_quantity();
        void updateStatus();
        void pay_order();
        void display();
        virtual ~Transaction();

    protected:
};

#endif // TRANSACTION_H
