#pragma once
#include "types.hpp"

struct Order{
    OrderId id;
    Side side;
    OrderType type;
    Price price;
    Quantity remainingQuantity;

    Order(OrderId   id_,
          Side      side_,
          OrderType type_,
          Price     price_,
          Quantity  remainingQuantity_)
        : id(id_)
        , side(side_)
        , type(type_)
        , price(price_)
        , remainingQuantity(remainingQuantity_)
    {}

};
