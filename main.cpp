#include "order_book.hpp"

#include <cassert>
#include <iostream>

int main() {
    OrderBook book;

    book.addOrder(Order{1, Side::Buy,  OrderType::Limit, 10000, 50});
    book.addOrder(Order{2, Side::Buy,  OrderType::Limit, 10000, 30});
    book.addOrder(Order{3, Side::Buy,  OrderType::Limit, 10100, 20});
    book.addOrder(Order{4, Side::Sell, OrderType::Limit, 10200, 40});
    book.addOrder(Order{5, Side::Sell, OrderType::Limit, 10300, 60});

    // Best bid = highest buy price = 101
    assert(book.bestBidLevel() != nullptr);
    assert(book.bestBidLevel()->price() == 10100);

    // Best ask = lowest sell price = 102
    assert(book.bestAskLevel() != nullptr);
    assert(book.bestAskLevel()->price() == 10200);

    // The 100 level has two orders (the try_emplace "existing key" path)
    // We can't reach bids_ directly, but we can reach it via... hmm,
    // we don't have a public accessor for a specific level yet.
    // Options: add a test-only helper, or probe indirectly.

    std::cout << "bestBid.price = " << book.bestBidLevel()->price() << '\n';
    std::cout << "bestAsk.price = " << book.bestAskLevel()->price() << '\n';
    return 0;
}