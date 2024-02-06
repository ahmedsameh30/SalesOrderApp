#ifndef PAYMENT_H
#define PAYMENT_H

#include<bits/stdc++.h>
using namespace std;

class Payment
{
    private :
        double amount;
    public :
        Payment();
        Payment(double);
        double pay();
        virtual ~Payment();

    protected:
};

#endif // PAYMENT_H
