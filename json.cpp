#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
  nlohmann::json j =
      "{\"Product\":[{\"name\":\"chleb\",\"price\":450,\"weight\":350},{\"name\":\"piwo\",\"price\":350,\"weight\":500},{\"name\":\"papier toaletowy\",\"price\":10000,\"weight\":100},{\"name\":\"płyn dezynfekujacy Orlen\",\"price\":14000,\"weight\":1500}]}"_json;

  for (const auto& it : j["Product"]) {
    if (it["name"] == "chleb") std::cout << it.value("price", 0) << std::endl;
  }
}
