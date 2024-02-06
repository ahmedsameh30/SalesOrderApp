#include "Order.h"
using namespace std;

Order::Order():id(""),number(""),date(""),total(0)
{
    //ctor
}

void Order::create_order()
{
    string c_id,type;
    cout<<"\n\t What is customer type ?\n"
        <<"\t 1) person\n"
        <<"\t 2) company\n"
        <<"\t Enter your choice : "; int c; cin>>c;
    cout<<"\t Enter customer id : "; cin>>c_id;
    if(c == 1){
        customer = new Person(); type = "person";
    }
    else if(c == 2){
        customer = new Company(); type = "company";
    }

    while(!customer->search_customer(c_id)){
        cout<<"\t this id isn't exist!\n";
        cout<<"\t Enter customer id : "; cin>>c_id;
    }

    cout<<"\n\t Enter order number : "; cin>>number;
    cout<<"\t Enter order id : "; cin>>id;

    stock.display();

    cout<<"\n\t How many items do you want to order ? ";
    int items; cin>>items;

    if(items > stock.getProductCount()){
        cout<<"\n\t Invalid !\n"; return;
    }
    while(items--){
        string id; int quantity;
        cout<<"\n\t Enter product id : "; cin>>id;
        cout<<"\t Enter the required quantity : "; cin>>quantity;
        if(!stock.search_for_product(id)){
            cout<<"\t this id is invalid\n";
            ++items; continue;
        }
        if(stock.get_product_quantity(id) == -1){
            ++items; continue;
        }
        if(quantity > stock.get_product_quantity(id)){
            cout<<"\t this quantity is invalid ! .. enter new value\n";
            ++items; continue;
        }
        stock.update_product_quantity_after_order_or_return(id,quantity,'-');
        total += (stock.get_product_price(id)*quantity);
    }
    status = OrderStatus::NEW;

    time_t now = time(0);
    date = ctime(&now);

    order.open("Orders.txt",ios::app);
    order<<number<<'|'<<id<<'|'<<status<<'|'<<date<<'|'<<total<<'|'<<c_id<<'|'<<type<<'\n';
    order.close();
}
void Order::update_status(string Id,int st)
{
    if(is_exist(Id)){
        fstream temp;

        order.open("Orders.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!order.eof()){
            order.getline(_number,7,'|');
            order.getline(_id,10,'|');
            order.getline(_status,3,'|');
            order.getline(_date,35,'|');
            order.getline(_total,12,'|');
            order.getline(_c_id,10,'|');
            order.getline(_type,9);

            if(_id == Id){
                switch(st){
                    case 1 :
                        status = OrderStatus::NEW;
                        break;
                    case 2 :
                        status = OrderStatus::HOLD;
                        break;
                    case 3 :
                        status = OrderStatus::PAID;
                        break;
                    case 4 :
                        status = OrderStatus::CANCELLED;
                        break;
                    default :
                        break;
                }
                temp<<_number<<'|'<<_id<<'|'<<status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
            else{
                temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
        }
        order.close();
        temp.close();

        order.open("Orders.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_number,7,'|');
            temp.getline(_id,10,'|');
            temp.getline(_status,3,'|');
            temp.getline(_date,35,'|');
            temp.getline(_total,12,'|');
            temp.getline(_c_id,10,'|');
            temp.getline(_type,9);

            order<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
        }
        order.close();
        temp.close();
        remove("temp.txt");
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
void Order::update_status_after_paid(string Id,double paid_amount)
{
    if(is_exist(Id)){
        fstream temp;

        order.open("Orders.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!order.eof()){
            order.getline(_number,7,'|');
            order.getline(_id,10,'|');
            order.getline(_status,3,'|');
            order.getline(_date,35,'|');
            order.getline(_total,12,'|');
            order.getline(_c_id,10,'|');
            order.getline(_type,9);

            if(_id == Id){
                string t = _total;
                total = stoi(_total);
                if(total-paid_amount == 0){
                    status = OrderStatus::PAID;
                }
                else if(total-paid_amount > 0){
                    status = OrderStatus::HOLD;
                }
                temp<<_number<<'|'<<_id<<'|'<<status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
            else{
                temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
        }
        order.close();
        temp.close();

        order.open("Orders.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_number,7,'|');
            temp.getline(_id,10,'|');
            temp.getline(_status,3,'|');
            temp.getline(_date,35,'|');
            temp.getline(_total,12,'|');
            temp.getline(_c_id,10,'|');
            temp.getline(_type,9);

            order<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
        }
        order.close();
        temp.close();
        remove("temp.txt");
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
void Order::returning_some_items(string Id)
{
    if(is_exist(Id)){
        cout<<"\n\t How many items would you like to return ?\n";
        int items; cin>>items;

        if(items > stock.getProductCount()){
            cout<<"\n\t Invalid!\n"; return;
        }
        while(items--){
            string p_id;
            int quan;

            cout<<"\t Enter product id : ";
            cin>>p_id;
            cout<<"\t Enter the returned quantity : ";
            cin>>quan;

            stock.update_product_quantity_after_order_or_return(p_id,quan,'+');
            int price = stock.get_product_price(p_id)*quan;

            fstream temp;

            order.open("Orders.txt",ios::in);
            temp.open("temp.txt",ios::out);
            while(!order.eof()){
                order.getline(_number,7,'|');
                order.getline(_id,10,'|');
                order.getline(_status,3,'|');
                order.getline(_date,35,'|');
                order.getline(_total,12,'|');
                order.getline(_c_id,10,'|');
                order.getline(_type,9);

                if(_id == Id){
                    string t = _total;
                    total = stoi(t);
                    total -= price;
                    temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<total<<'|'<<_c_id<<'|'<<_type<<'\n';
                }
                else{
                    temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
                }
            }
            order.close();
            temp.close();

            order.open("Orders.txt",ios::out);
            temp.open("temp.txt",ios::in);
            while(!temp.eof()){
                temp.getline(_number,7,'|');
                temp.getline(_id,10,'|');
                temp.getline(_status,3,'|');
                temp.getline(_date,35,'|');
                temp.getline(_total,12,'|');
                temp.getline(_c_id,10,'|');
                temp.getline(_type,9);

                order<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
            order.close();
            temp.close();
            remove("temp.txt");
        }
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
void Order::ordering_more_items(string Id)
{
    if(is_exist(Id)){
        cout<<"\n\t How many items would you like to order more ?\n";
        int items; cin>>items;

        if(items > stock.getProductCount()){
            cout<<"\n\t Invalid!\n"; return;
        }
        while(items--){
            string p_id;
            int quan;

            cout<<"\t Enter product id : ";
            cin>>p_id;
            cout<<"\t Enter the required quantity : ";
            cin>>quan;
            if(quan > stock.get_product_quantity(p_id)){
                cout<<"\t Invalid ! .. Enter new value\n";
                ++items; continue;
            }
            stock.update_product_quantity_after_order_or_return(p_id,quan,'-');
            int price = stock.get_product_price(p_id)*quan;

            fstream temp;

            order.open("Orders.txt",ios::in);
            temp.open("temp.txt",ios::out);
            while(!order.eof()){
                order.getline(_number,7,'|');
                order.getline(_id,10,'|');
                order.getline(_status,3,'|');
                order.getline(_date,35,'|');
                order.getline(_total,12,'|');
                order.getline(_c_id,10,'|');
                order.getline(_type,9);

                if(_id == Id){
                    string t = _total;
                    total = stoi(t);
                    total += price;
                    temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<total<<'|'<<_c_id<<'|'<<_type<<'\n';
                }
                else{
                    temp<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
                }
            }
            order.close();
            temp.close();

            order.open("Orders.txt",ios::out);
            temp.open("temp.txt",ios::in);
            while(!temp.eof()){
                temp.getline(_number,7,'|');
                temp.getline(_id,10,'|');
                temp.getline(_status,3,'|');
                temp.getline(_date,35,'|');
                temp.getline(_total,12,'|');
                temp.getline(_c_id,10,'|');
                temp.getline(_type,9);

                order<<_number<<'|'<<_id<<'|'<<_status<<'|'<<_date<<'|'<<_total<<'|'<<_c_id<<'|'<<_type<<'\n';
            }
            order.close();
            temp.close();
            remove("temp.txt");
        }
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
int Order::getTotal(string Id)
{
    if(is_exist(Id)){
        order.open("Orders.txt",ios::in);
        while(!order.eof()){
            order.getline(_number,7,'|');
            order.getline(_id,10,'|');
            order.getline(_status,3,'|');
            order.getline(_date,35,'|');
            order.getline(_total,12,'|');
            order.getline(_c_id,10,'|');
            order.getline(_type,9);

            if(_id == Id){
                string t = _total;
                total = stoi(t);
            }
        }
        order.close();
        return total;
    }
    else{
        cout<<"\t Error!! .. this id isn't exist\n";
    }
}
bool Order::is_exist(string Id)
{
    bool f = false;
    order.open("Orders.txt",ios::in);
    while(!order.eof()){
        order.getline(_number,7,'|');
        order.getline(_id,10,'|');
        order.getline(_status,3,'|');
        order.getline(_date,35,'|');
        order.getline(_total,12,'|');
        order.getline(_c_id,10,'|');
        order.getline(_type,9);

        if(_id == Id){
            f = true;
        }
    }
    order.close();
    return f;
}
void Order::display_orders_details()
{
    order.open("Orders.txt",ios::in);
    while(!order.eof()){
        order.getline(_number,7,'|');
        order.getline(_id,10,'|');
        order.getline(_status,3,'|');
        order.getline(_date,35,'|');
        order.getline(_total,12,'|');
        order.getline(_c_id,10,'|');
        order.getline(_type,9);

        cout<<"\n-------------------------------------------------------------\n";
        cout<<"\t number :- "<<_number<<"\t"<<"id :- "<<_id<<"\t"<<"amount :- "<<_total<<"\n";
        cout<<"\t date :- "<<_date<<"\t"<<"customer id :- "<<_c_id<<"\t"<<"type :- "<<_type<<"\n";
        if(_status[0] == '0')cout<<"\t order status :- New\n";
        else if(_status[0] == '1')cout<<"\t order status :- Hold\n";
        else if(_status[0] == '2')cout<<"\t order status :- Paid\n";
        else if(_status[0] == '3')cout<<"\t order status :- Cancelled\n";
    }
    order.close();
}

Order::~Order()
{
    //dtor
}
