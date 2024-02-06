#ifndef ORDERITEM_H
#define ORDERITEM_H


class OrderItem
{
    private :
        double sale_price;
        int quantity;
    public :
        OrderItem();
        OrderItem(double,int);
        double get_price();
        void update_quantity();
        virtual ~OrderItem();

    protected:
};

#endif // ORDERITEM_H
