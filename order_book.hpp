#pragma once
#include "types.hpp"
#include "price_level.hpp"
#include <map>
#include <functional>
#include <cassert>

class OrderBook{
    private:
        std::map<Price,PriceLevel, std::greater<Price>> bids_;
        std::map<Price,PriceLevel> asks_;

    public:
        PriceLevel* bestBidLevel(){
            if(bids_.empty()){
                return nullptr;
            }
            return &bids_.begin()->second;
        };
        PriceLevel* bestAskLevel(){
            if(asks_.empty()){
                return nullptr;
            }
            return &asks_.begin()->second;
        };
        
        void addOrder(const Order& order){
            assert(order.type == OrderType::Limit && "only limit orders are supported for now");

           switch(order.side){
                case Side::Buy: {
                    auto result = bids_.try_emplace(order.price, order.price);
                    result.first->second.addOrder(order);
                    break;
                }
                case Side::Sell: {
                    auto result = asks_.try_emplace(order.price, order.price);
                    result.first->second.addOrder(order);
                    break;
                }
           }
        };
};