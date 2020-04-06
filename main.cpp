#include "src/Store.hpp"
#include "src/client.hpp"

int main() {
  client test;
  nlohmann::json k;
  Store stock;

  test.importProducts(k);

  std::cout << k.dump(4) << std::endl;
}
