#pragma once

#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <cstdlib>

class client{
public:
  client():url(""){}
  bool getProducts(nlohmann::json&);
  bool getFinalPrice(int& price);
  void setAddr(const std::string & new_url){url = new_url;}
private:
  std::string url;

};
