#include "online_store.hpp"
#include <iostream>

bool online_store::init() {
  nlohmann::json products;

  if (!importProducts(products)) return false;

  setProducts(products);
  return true;
}

bool online_store::computeGrossPrice() {
  unsigned long int price = get_price();

  if (!importFinalPrice(price)) return false;

  return true;
}
