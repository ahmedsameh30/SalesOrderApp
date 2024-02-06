#include "Person.h"
#include<iostream>
using namespace std;

Person::Person():Customer(),fullname(""),billing_address("")
{
    //ctor
}

void Person::add_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    cout<<"\t Enter the name : ";
    cin.ignore(); getline(cin,fullname);

    cout<<"\t Enter phone number : ";
    cin>>phone;

    cout<<"\t Enter email : ";
    cin>>email;

    cout<<"\t Enter billing address : ";
    cin>>billing_address;

    person.open("Person.txt",ios::app);
    person<<id<<'|'<<fullname<<'|'<<phone<<'|'<<email<<'|'<<billing_address<<'\n';
    person.close();
}
void Person::update_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    if(search_customer(id)){
        fstream temp;
        person.open("Person.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!person.eof()){
            person.getline(_id,10,'|');
            person.getline(_fullname,50,'|');
            person.getline(_phone,13,'|');
            person.getline(_email,40,'|');
            person.getline(_billing_address,40);

            if(_id == id){
                cout<<"\n\t What would you like to update ?\n"
                    <<"\t 1- id\n"
                    <<"\t 2- name\n"
                    <<"\t 3- phone\n"
                    <<"\t 4- email\n"
                    <<"\t 5- billing address\n";
                int c;
                cout<<"\n\t Enter your choice : "; cin>>c;
                switch(c){
                    case 1 :
                        cout<<"\t Enter the new id : ";
                        cin>>_id;
                        break;
                    case 2 :
                        cout<<"\t Enter the new name : ";
                        cin.ignore(); cin.getline(_fullname,50);
                        break;
                    case 3 :
                        cout<<"\t Enter the new phone : ";
                        cin>>_phone;
                        break;
                    case 4 :
                        cout<<"\t Enter the new email : ";
                        cin>>_email;
                        break;
                    case 5 :
                        cout<<"\t Enter the new billing address : ";
                        cin.ignore(); cin.getline(_billing_address,40);
                        break;
                    default :
                        cout<<"\t Invalid choice!\n"; return;
                }
            }
            temp<<_id<<'|'<<_fullname<<'|'<<_phone<<'|'<<_email<<'|'<<_billing_address<<'\n';
        }
        person.close();
        temp.close();

        person.open("Person.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_fullname,50,'|');
            temp.getline(_phone,13,'|');
            temp.getline(_email,40,'|');
            temp.getline(_billing_address,40);

            person<<_id<<'|'<<_fullname<<'|'<<_phone<<'|'<<_email<<'|'<<_billing_address<<'\n';
        }
        person.close();
        temp.close();
        remove("temp.txt");
        cout<<"\t Updated successfully..\n";
    }
    else{
        cout<<"\t Error!! .. This id isn't exist\n";
    }
}
bool Person::search_customer(string Id)
{
    bool isExist = false;
    person.open("Person.txt",ios::in);
    while(!person.eof()){
        person.getline(_id,10,'|');
        person.getline(_fullname,50,'|');
        person.getline(_phone,13,'|');
        person.getline(_email,40,'|');
        person.getline(_billing_address,40);

        if(_id == Id){
            isExist = true;
        }
    }
    person.close();
    return isExist;
}
void Person::delete_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    if(search_customer(id)){
        fstream temp;
        person.open("Person.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!person.eof()){
            person.getline(_id,10,'|');
            person.getline(_fullname,50,'|');
            person.getline(_phone,13,'|');
            person.getline(_email,40,'|');
            person.getline(_billing_address,40);

            if(_id != id){
                temp<<_id<<'|'<<_fullname<<'|'<<_phone<<'|'<<_email<<'|'<<_billing_address<<'\n';
            }
        }
        person.close();
        temp.close();

        person.open("Person.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_fullname,50,'|');
            temp.getline(_phone,13,'|');
            temp.getline(_email,40,'|');
            temp.getline(_billing_address,40);

            person<<_id<<'|'<<_fullname<<'|'<<_phone<<'|'<<_email<<'|'<<_billing_address<<'\n';
        }
        person.close();
        temp.close();
        remove("temp.txt");
        cout<<"\n\t Deleted successfully..\n";
    }
    else{
        cout<<"\n\t Error!! .. This id isn't exist\n";
    }
}
int Person::total_number_of_customers()
{
    int cnt = 0;
    person.open("Person.txt",ios::in);
    while(!person.eof()){
        person.getline(_id,10,'|');
        person.getline(_fullname,50,'|');
        person.getline(_phone,13,'|');
        person.getline(_email,40,'|');
        person.getline(_billing_address,40);

        id = _id;
        if(id.length() > 0){
            ++cnt;
        }
    }
    person.close();
    return cnt;
}
void Person::display()
{
    person.open("Person.txt",ios::in);
    while(!person.eof()){
        person.getline(_id,10,'|');
        person.getline(_fullname,50,'|');
        person.getline(_phone,13,'|');
        person.getline(_email,40,'|');
        person.getline(_billing_address,40);

        id = _id;
        if(id.length() >= 1){
            cout<<"\n-------------------------------------------------------------------------\n";
            cout<<"\t id :- "<<_id<<"\t name :- "<<_fullname<<"\t phone :- "<<_phone<<"\n"
                <<"\t email :- "<<_email<<"\t billing address :- "<<_billing_address;
        }
    }
    person.close();
    cout<<endl;
}

Person::~Person()
{
    //dtor
}
