#pragma once

#include <algorithm>
#include <nlohmann/json.hpp>
#include <vector>

class Store {
 public:
  void setProducts(nlohmann::json &products) { stock = products; }
  const unsigned long int &get_price() { return net_price; }
  bool addToBasket(const std::string &);
  bool removeFromBasket(const std::string &);
  void clearBasket() { basket.clear(); }
  void clearPrice() { net_price = 0; }
  bool emptyBasket() { return basket.empty(); }
  bool emptyStock() { return stock.empty(); }

 private:
  std::vector<std::string> basket;
  nlohmann::json stock;
  unsigned long int net_price = 0;
};
