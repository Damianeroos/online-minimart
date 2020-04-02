#include "Store.hpp"

bool Store::addToBasket(std::string& item) {
  if (!stock.contains(item))  // no item in store
    return false;

  basket.push_back(item);
  return true;
}

bool Store::removeFromBasket(std::string& item) {
  std::vector<std::string>::iterator it =
      std::find(basket.begin(), basket.end(), item);

  if (it == basket.end()) return false;

  basket.erase(it);

  return true;
}
