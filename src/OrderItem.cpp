#include "OrderItem.h"

OrderItem::OrderItem():sale_price(0),quantity(0)
{
    //ctor
}
OrderItem::OrderItem(double _sale_price,int _quantity)
{
    sale_price = _sale_price;
    quantity = _quantity;
}
double OrderItem::get_price()
{
    return sale_price*quantity;
}
void OrderItem::update_quantity()
{

}

OrderItem::~OrderItem()
{
    //dtor
}
