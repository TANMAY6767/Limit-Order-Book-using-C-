#pragma once
#include <cstdint>

using OrderId = std::uint64_t;
using Price = std::int64_t;
using Quantity  = std::uint64_t;

enum class Side{
    Buy,
    Sell
};
enum class OrderType{
    Limit,
    Market
};