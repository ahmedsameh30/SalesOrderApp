#include<iostream>
#include<ctime>
#include "Customers.h"
#include "Stock.h"
#include "Transaction.h"
using namespace std;

void data_entry()
{
    int c = 0;
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t [1] Customers\n"
        <<"\t [2] Stock\n";
    cout<<"\n\t Enter your choice : "; cin>>c;
    switch(c){
        case 1 :
            {
                Customers cust;
                cout<<"\n-------------------------------------------------------------\n";
                cout<<"\t [1] Add new customer\n"
                    <<"\t [2] Update customer info\n"
                    <<"\t [3] Delete customer\n"
                    <<"\t [4] Number of total registered customers\n";
                cout<<"\n\t Enter your choice : "; int x; cin>>x;
                switch(x){
                    case 1 :
                        cust.add_customer();
                        break;
                    case 2 :
                        cust.update_customer();
                        break;
                    case 3 :
                        cust.delete_customer();
                        break;
                    case 4 :
                        {
                            int num = cust.total_number_of_customers();
                            if(num){
                                cout<<"\t Total number is : "<<num<<endl;
                            }
                        }
                        break;
                    default :
                        cout<<"\t Invalid choice!\n";
                }
            }
            break;
        case 2 :
            {
                Stock stock;
                cout<<"\n-------------------------------------------------------------\n";
                cout<<"\t [1] Add new product\n"
                    <<"\t [2] Update product info\n"
                    <<"\t [3] Delete product\n"
                    <<"\t [4] Number of products in stock\n";
                cout<<"\n\t Enter your choice : "; int x; cin>>x;
                switch(x){
                    case 1 :
                        stock.add_to_stock();
                        break;
                    case 2 :
                        stock.update_stock();
                        break;
                    case 3 :
                        stock.delete_product_in_stock();
                        break;
                    case 4 :
                        stock.getProductCount();
                        break;
                    default :
                        cout<<"\t Invalid choice!\n";
                }
            }
            break;
        default :
            cout<<"\t Invalid choice!\n";
    }
}
void sales_process()
{
    Transaction transaction;
    int c = 0;
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t [1] Add transaction (make order)\n"
        <<"\t [2] Update order\n"
        <<"\t [3] Pay order\n";
    cout<<"\n\t Enter your choice : "; cin>>c;
    switch(c){
        case 1 :
            transaction.make_order();
            break;
        case 2 :
            {
                cout<<"\n-------------------------------------------------------------\n";
                cout<<"\t 1- Order item quantity\n"
                    <<"\t 2- Order Status\n";
                cout<<"\t Enter your choice : "; int c; cin>>c;
                switch(c){
                    case 1 :
                        transaction.update_order_items_quantity();
                        break;
                    case 2 :
                        transaction.updateStatus();
                        break;
                    default :
                        cout<<"\t Invalid choice!\n";
                }
            }
            break;
        case 3 :
            transaction.pay_order();
            break;
        default :
            cout<<"\t Invalid choice!\n";
    }
}
void display()
{
    int c = 0;
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\t [1] Customers\n"
        <<"\t [2] Stock data\n"
        <<"\t [3] Transactions\n";
    cout<<"\n\t Enter your choice : "; cin>>c;
    switch(c){
        case 1 :
            {
                Customers cust;
                cust.display();
            }
            break;
        case 2 :
            {
                Stock s;
                s.display();
            }
            break;
        case 3 :
            {
                Transaction t;
                t.display();
            }
            break;
        default :
            cout<<"\t Invalid choice!\n";
    }
}
void sales_order_system()
{
    int c = 1;
    while(c != 0){
        cout<<"===============================================================\n";
        cout<<"\t ##Main Menu..\n"
            <<"\t [1] Data Entry\n"
            <<"\t [2] Sales Process\n"
            <<"\t [3] Display\n"
            <<"\t [0] Exit";
        cout<<"\n\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                data_entry();
                break;
            case 2 :
                sales_process();
                break;
            case 3 :
                display();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid number !  Try again please..\n";
        }
    }
}
int main()
{
    sales_order_system();
    return 0;
}
