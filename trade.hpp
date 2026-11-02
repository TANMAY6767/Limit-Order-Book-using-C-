#pragma once
#include "types.hpp"

struct Trade{
    OrderId buyOrderId;
    OrderId sellOrderId;
    Price price;
    Quantity executedQuantity;

    Trade(OrderId   buyOrderId_,
          OrderId      sellOrderId_,
          Price price_,
          Quantity     executedQuantity_)
        : buyOrderId(buyOrderId_)
        , sellOrderId(sellOrderId_)
        , price(price_)
        , executedQuantity(executedQuantity_)
    {}
};