#pragma once

#include <nlohmann/json.hpp>
#include <iostream>

class products{
public:
  products();
  bool setProduct(std::string name,int price,int weight);
  nlohmann::json get(){return value;}
  void print(){std::cout<<value.dump(4)<<std::endl;}
private:
  nlohmann::json value;
  
};

