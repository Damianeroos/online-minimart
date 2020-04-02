#include "src/client.hpp"

int main() {
  client test;
  nlohmann::json k;
  int price = 100;
  test.importProducts(k);
  test.importFinalPrice(price);
  std::cout << price << std::endl;
}
