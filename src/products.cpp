#include "products.hpp"

bool products::setProduct(std::string name,int price,int weight){
  if(price < 0 || weight < 0){
    std::cerr<<"Typed value can not be negative\n";
    return false;
  }
  
  if(value.is_null())
    value["Product"] = {{{"name",name},{"price",price},{"weight",weight}}};
  else{
    nlohmann::json temp = {{"name",name},{"price",price},{"weight",weight}};
    value["Product"].push_back(temp);
  }
  return true;
}

products::products(){
  setProduct("chleb",450,350);
  setProduct("piwo",350,500);
  setProduct("papier toaletowy",10000,100);
  setProduct("płyn dezynfekujacy Orlen",14000,1500);
}
