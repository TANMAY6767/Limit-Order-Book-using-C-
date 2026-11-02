#pragma once
#include "types.hpp"
#include "order.hpp"
#include <list>
#include <cassert>
class PriceLevel{
    public:
        explicit PriceLevel(Price price_)
            : price_(price_)
        {}

        void addOrder(const Order& o){
            assert(o.price == price_ && "order price must match the level");
            orders_.push_back(o);
        }
        
        Price price() const {
            return price_;
        }
        const std::list<Order>& orders() const{
            return orders_;
        }

        bool empty() const {
            return orders_.empty();
        }
        const Order& oldestOrder() const {
            assert(!orders_.empty() && "oldestOrder() called on an empty PriceLevel");
            return orders_.front();
        }

        void applyExecution(Quantity executedQuantity){
            assert(!orders_.empty() && "applyExecution() called on an empty PriceLevel");
            assert(executedQuantity > 0 && "executedQuantity must be positive");
            assert(executedQuantity <= orders_.front().remainingQuantity
               && "executedQuantity exceeds the oldest order's remaining quantity");

            orders_.front().remainingQuantity -= executedQuantity;
            if (orders_.front().remainingQuantity == 0) {
                orders_.pop_front();
            }
        }   

    private:
        Price price_;
        std::list<Order> orders_;

};