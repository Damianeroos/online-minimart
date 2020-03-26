#pragma once

#include <nlohmann/json.hpp>
#include <curl/curl.h>

class client{
public:
  client():addr("localhost:1234"){}
  bool getProducts(const nlohmann::json&);
  bool getFinalPrice(const nlohmann::json,int&);
  void setAddr(const std::string & new_addr){addr = new_addr;}
private:
  std::string addr;
};
