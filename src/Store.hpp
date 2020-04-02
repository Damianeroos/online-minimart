#pragma once

#include <algorithm>
#include <nlohmann/json.hpp>
#include <vector>

class Store {
 public:
  void setProducts(nlohmann::json &products) { stock = products; }
  const int &get_price() { return net_price; }
  bool addToBasket(std::string &);
  bool removeFromBasket(std::string &);
  void clearBasket() { basket.clear(); }
  void clearPrice() { net_price = 0; }

 private:
  std::vector<std::string> basket;
  nlohmann::json stock;
  int net_price;
};
