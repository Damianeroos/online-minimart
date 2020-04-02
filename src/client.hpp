#pragma once

#include <cstdlib>
#include <curlpp/Easy.hpp>
#include <curlpp/Infos.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <nlohmann/json.hpp>
#include <sstream>

class client {
 public:
  client() : url("http://localhost:1234/") {}
  bool importProducts(nlohmann::json& products);
  bool importFinalPrice(int& price);
  void setAddr(const std::string& new_url) { url = new_url; }

 private:
  std::string url;
};
