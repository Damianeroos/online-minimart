#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

class products {
 public:
  products();
  bool setProduct(std::string name, int price, int weight);
  nlohmann::json get() { return value; }
  void print() { std::cout << value.dump(4) << std::endl; }

 private:
  nlohmann::json value;
};
