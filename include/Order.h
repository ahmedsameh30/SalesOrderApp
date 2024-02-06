#ifndef ORDER_H
#define ORDER_H

#include<bits/stdc++.h>
#include "Stock.h"
#include "Customer.h"
#include "Person.h"
#include "Company.h"

using namespace std;

enum OrderStatus {NEW,HOLD,PAID,CANCELLED};

class Order
{
    private :
        Customer* customer;
        Stock stock;

        string id;
        string number;
        string date;
        int status;
        int total;

        char _id[10];
        char _number[7];
        char _date[35];
        char _status[3];
        char _total[12];
        char _c_id[10];
        char _type[9];

        fstream order;
    public :
        Order();
        void create_order();
        void update_status(string,int);
        void update_status_after_paid(string,double);
        void returning_some_items(string);
        void ordering_more_items(string);
        int getTotal(string);
        bool is_exist(string);
        void display_orders_details();
        virtual ~Order();

    protected:
};

#endif // ORDER_H
