#include "Store.hpp"
#include <iostream>

bool Store::addToBasket(const std::string& item) {
  if (emptyStock()) {
    return false;
  }

  for (const auto& it : stock["Product"]) {
    if (it["name"] == item) {
      basket.push_back(item);
      net_price += it.value("price", 0);
      return true;
    }
  }

  return false;
}

bool Store::removeFromBasket(const std::string& item) {
  std::vector<std::string>::iterator it =
      std::find(basket.begin(), basket.end(), item);

  if (it == basket.end()) return false;

  basket.erase(it);

  return true;
}
