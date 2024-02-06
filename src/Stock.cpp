#include "Stock.h"
#include<bits/stdc++.h>
using namespace std;

Stock::Stock()
{
    //ctor
}

void Stock::add_to_stock()
{
    cout<<"\n\t Enter product id : ";
    cin>>product.id;

    cout<<"\t Enter product name : ";
    cin.ignore(); getline(cin,product.name);

    cout<<"\t Enter product price : ";
    cin>>product.price;

    cout<<"\t Enter product quantity : ";
    cin>>product.quantity;

    stock.open("Stock.txt",ios::app);
    stock<<product.id<<'|'<<product.name<<'|'<<product.price<<'|'<<product.quantity<<'\n';
    stock.close();
}
void Stock::update_stock()
{
    cout<<"\n\t Enter product id to edit : ";
    cin>>product.id;

    if(search_for_product(product.id)){
        fstream temp;

        stock.open("Stock.txt",ios::in);
        temp.open("temp.txt",ios::out);

        while(!stock.eof()){
            stock.getline(_id,10,'|');
            stock.getline(_name,30,'|');
            stock.getline(_price,10,'|');
            stock.getline(_quantity,10);

            if(_id == product.id){
                string up; int c;
                cout<<"\n\t What do you want to update ?\n";
                cout<<"\t 1- id\n"
                    <<"\t 2- name\n"
                    <<"\t 3- price\n"
                    <<"\t 4- quantity\n";
                cout<<"\n\t Enter your choice : "; cin>>c;
                switch(c){
                    case 1 :
                        cout<<"\t Enter the new id : ";
                        cin>>_id;
                        break;
                    case 2 :
                        cout<<"\t Enter the new name : ";
                        cin.ignore(); cin.getline(_name,30);
                        break;
                    case 3 :
                        cout<<"\t Enter the new price : ";
                        cin>>_price;
                        break;
                    case 4 :
                        cout<<"\t Enter the new quantity : ";
                        cin>>_quantity;
                        break;
                    default :
                        cout<<"\n\t Invalid choice!!\n";
                }
            }
            temp<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
        }
        stock.close();
        temp.close();

        stock.open("Stock.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_name,30,'|');
            temp.getline(_price,10,'|');
            temp.getline(_quantity,10);

            stock<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
        }
        stock.close();
        temp.close();
        remove("temp.txt");
        cout<<"\t Updated successfully..\n";
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
void Stock::update_product_quantity_after_order_or_return(string id,int new_quantity,char op)
{
    if(search_for_product(id)){
        fstream temp;

        stock.open("Stock.txt",ios::in);
        temp.open("temp.txt",ios::out);

        while(!stock.eof()){
            stock.getline(_id,10,'|');
            stock.getline(_name,30,'|');
            stock.getline(_price,10,'|');
            stock.getline(_quantity,10);

            if(_id == id){
                product.quantity = _quantity;
                int quan = stoi(product.quantity);
                if(op == '+')quan += new_quantity;
                else quan -= new_quantity;
                temp<<_id<<'|'<<_name<<'|'<<_price<<'|'<<quan<<'\n';
            }
            else{
                temp<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
            }
        }
        stock.close();
        temp.close();

        stock.open("Stock.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_name,30,'|');
            temp.getline(_price,10,'|');
            temp.getline(_quantity,10);

            stock<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
        }
        stock.close();
        temp.close();
        remove("temp.txt");
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
void Stock::delete_product_in_stock()
{
    cout<<"\n\t Enter product id : ";
    cin>>product.id;

    if(search_for_product(product.id)){
        fstream temp;

        stock.open("Stock.txt",ios::in);
        temp.open("temp.txt",ios::out);

        while(!stock.eof()){
            stock.getline(_id,10,'|');
            stock.getline(_name,30,'|');
            stock.getline(_price,10,'|');
            stock.getline(_quantity,10);

            if(_id != product.id){
                temp<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
            }
        }
        stock.close();
        temp.close();

        stock.open("Stock.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_name,30,'|');
            temp.getline(_price,10,'|');
            temp.getline(_quantity,10);

            stock<<_id<<'|'<<_name<<'|'<<_price<<'|'<<_quantity<<'\n';
        }
        stock.close();
        temp.close();
        remove("temp.txt");
        cout<<"\t Deleted successfully..\n";
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
int Stock::getProductCount()
{
    int cnt = 0;
    stock.open("Stock.txt",ios::in);
    while(!stock.eof()){
        stock.getline(_id,10,'|');
        stock.getline(_name,30,'|');
        stock.getline(_price,10,'|');
        stock.getline(_quantity,10);

        product.id = _id;
        if(product.id.length() >= 1)++cnt;
    }
    stock.close();
    return cnt;
}
int Stock::get_product_quantity(string id)
{
    int quan = -1;
    if(search_for_product(id)){
        stock.open("Stock.txt",ios::in);
        while(!stock.eof()){
            stock.getline(_id,10,'|');
            stock.getline(_name,30,'|');
            stock.getline(_price,10,'|');
            stock.getline(_quantity,10);

            if(_id == id){
                product.quantity = _quantity;
                quan = stoi(product.quantity);
            }
        }
        stock.close();
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
    return quan;
}
double Stock::get_product_price(string id)
{
    double price = -1;
    if(search_for_product(id)){
        stock.open("Stock.txt",ios::in);
        while(!stock.eof()){
            stock.getline(_id,10,'|');
            stock.getline(_name,30,'|');
            stock.getline(_price,10,'|');
            stock.getline(_quantity,10);

            if(_id == id){
                product.price = _price;
                price = stoi(product.price);
            }
        }
        stock.close();
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
    return price;
}
bool Stock::search_for_product(string id)
{
    bool isExist = false;
    stock.open("Stock.txt",ios::in);
    while(!stock.eof()){
        stock.getline(_id,10,'|');
        stock.getline(_name,30,'|');
        stock.getline(_price,10,'|');
        stock.getline(_quantity,10);

        if(id == _id){
            isExist = true;
        }
    }
    stock.close();
    return isExist;
}
void Stock::display()
{
    cout<<"\n*************************************************************";
    stock.open("Stock.txt",ios::in);
    while(!stock.eof()){
        stock.getline(_id,10,'|');
        stock.getline(_name,30,'|');
        stock.getline(_price,10,'|');
        stock.getline(_quantity,10);

        product.id = _id;
        if(product.id.length() >= 1){
            cout<<"\n\t id :- "<<_id<<"\t name :- "<<_name<<"\t price :- "<<_price<<"\t quantity :- "<<_quantity;
        }
    }
    stock.close();
    cout<<endl;
}
Stock::~Stock()
{
    //dtor
}
