#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
  json j;
  std::string s= "{\"name\":\"dupa\",\"weight\":93}";
  j = json::parse(s);
  // j["name"] = "dupa";
  // j["weight"] = 93;

  for (auto& it : j.items()) {
    if (it.key() == "weight") std::cout << it.value() << "\n";
  }
  std::cout<<j<<std::endl;
}
