#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include "Store.hpp"
#include "client.hpp"

class online_store : public Store, public client {
 public:
  online_store() : gross_price(0) {}
  bool init();
  const unsigned long int& getGrossPrice() const { return gross_price; }
  bool computeGrossPrice();

 private:
  unsigned long int gross_price;
};
