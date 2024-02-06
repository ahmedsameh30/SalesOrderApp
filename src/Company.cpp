#include "Company.h"

Company::Company():Customer(),comp_name(""),location("")
{
    //ctor
}

void Company::add_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    cout<<"\n\t Enter the name : ";
    cin.ignore(); getline(cin,comp_name);

    cout<<"\n\t Enter phone number : ";
    cin>>phone;

    cout<<"\n\t Enter email : ";
    cin>>email;

    cout<<"\n\t Enter location : ";
    cin.ignore(); getline(cin,location);

    company.open("Company.txt",ios::app);
    company<<id<<'|'<<comp_name<<'|'<<phone<<'|'<<email<<'|'<<location<<'\n';
    company.close();
}
void Company::update_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    if(search_customer(id)){
        fstream temp;
        company.open("Company.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!company.eof()){
            company.getline(_id,10,'|');
            company.getline(_comp_name,30,'|');
            company.getline(_phone,13,'|');
            company.getline(_email,40,'|');
            company.getline(_location,50);

            if(_id == id){
                cout<<"\n\t What would you like to update ?\n"
                    <<"\t 1- id\n"
                    <<"\t 2- name\n"
                    <<"\t 3- phone\n"
                    <<"\t 4- email\n"
                    <<"\t 5- location\n";
                int c;
                cout<<"\n\t Enter your choice : "; cin>>c;
                switch(c){
                    case 1 :
                        cout<<"\t Enter the new id : ";
                        cin>>_id;
                        break;
                    case 2 :
                        cout<<"\t Enter the new name : ";
                        cin.ignore(); cin.getline(_comp_name,30);
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
                        cout<<"\t Enter the new location : ";
                        cin.ignore(); cin.getline(_location,50);
                        break;
                    default :
                        cout<<"\t Invalid choice!\n"; return;
                }
            }
            temp<<_id<<'|'<<_comp_name<<'|'<<_phone<<'|'<<_email<<'|'<<_location<<'\n';
        }
        company.close();
        temp.close();

        company.open("Company.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_comp_name,30,'|');
            temp.getline(_phone,13,'|');
            temp.getline(_email,40,'|');
            temp.getline(_location,50);

            company<<_id<<'|'<<_comp_name<<'|'<<_phone<<'|'<<_email<<'|'<<_location<<'\n';
        }
        company.close();
        temp.close();
        remove("temp.txt");
        cout<<"\n\t Updated successfully..\n";
    }
    else{
        cout<<"\n\t Error!! .. This id isn't exist\n";
    }
}
bool Company::search_customer(string Id)
{
    bool isExist = false;
    company.open("Company.txt",ios::in);
    while(!company.eof()){
        company.getline(_id,10,'|');
        company.getline(_comp_name,30,'|');
        company.getline(_phone,13,'|');
        company.getline(_email,40,'|');
        company.getline(_location,50);

        if(_id == Id){
            isExist = true;
        }
    }
    company.close();
    return isExist;
}
void Company::delete_customer()
{
    cout<<"\n\t Enter the id : ";
    cin>>id;

    if(search_customer(id)){
        fstream temp;
        company.open("Company.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!company.eof()){
            company.getline(_id,10,'|');
            company.getline(_comp_name,30,'|');
            company.getline(_phone,13,'|');
            company.getline(_email,40,'|');
            company.getline(_location,50);

            if(_id != id){
                temp<<_id<<'|'<<_comp_name<<'|'<<_phone<<'|'<<_email<<'|'<<_location<<'\n';
            }
        }
        company.close();
        temp.close();

        company.open("Company.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,10,'|');
            temp.getline(_comp_name,30,'|');
            temp.getline(_phone,13,'|');
            temp.getline(_email,40,'|');
            temp.getline(_location,50);

            company<<_id<<'|'<<_comp_name<<'|'<<_phone<<'|'<<_email<<'|'<<_location<<'\n';
        }
        company.close();
        temp.close();
        remove("temp.txt");
        cout<<"\n\t Deleted successfully..\n";
    }
    else{
        cout<<"\n\t Error!! .. This id isn't exist\n";
    }
}
int Company::total_number_of_customers()
{
    int cnt = 0;
    company.open("Company.txt",ios::in);
    while(!company.eof()){
        company.getline(_id,10,'|');
        company.getline(_comp_name,30,'|');
        company.getline(_phone,13,'|');
        company.getline(_email,40,'|');
        company.getline(_location,50);

        id = _id;
        if(id.length() > 0){
            ++cnt;
        }
    }
    company.close();
    return cnt;
}
void Company::display()
{
    company.open("Company.txt",ios::in);
    while(!company.eof()){
        company.getline(_id,10,'|');
        company.getline(_comp_name,30,'|');
        company.getline(_phone,13,'|');
        company.getline(_email,40,'|');
        company.getline(_location,50);

        id = _id;
        if(id.length() >= 1){
            cout<<"\n-------------------------------------------------------------------------\n";
            cout<<"\t id :- "<<_id<<"\t name :- "<<_comp_name<<"\t phone :- "<<_phone<<"\n"
                <<"\t email :- "<<_email<<"\t location :- "<<_location;
        }
    }
    company.close();
    cout<<endl;
}

Company::~Company()
{
    //dtor
}
