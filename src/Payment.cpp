#include "Payment.h"
using namespace std;

Payment::Payment():amount(0)
{
    //ctor
}
Payment::Payment(double _amount):amount(_amount)
{

}

double Payment::pay()
{
    return amount;
}
Payment::~Payment()
{
    //dtor
}
