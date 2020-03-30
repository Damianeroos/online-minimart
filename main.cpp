#include "src/client.hpp"


int main(){
  client test;
  nlohmann::json k;
  test.importProducts(k);
  std::cout<<k.dump(4);
}
