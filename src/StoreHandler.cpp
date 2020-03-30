#include "StoreHandler.hpp"

using namespace Pistache;




void StoreHandler::publish(std::shared_ptr<Pistache::Rest::Router> router){
  using namespace Pistache::Rest;
  Routes::Get(*router, "/GetProducts", Routes::bind(&StoreHandler::sendProducts, this));
  Routes::Post(*router, "/GetPrice", Routes::bind(&StoreHandler::sendPrice, this));
}

void StoreHandler::sendProducts(Pistache::Rest::Request const& request,
					    Pistache::Http::ResponseWriter response){
  std::string message;
  
  if(request.query().as_str().empty()){ // only welcome addr but no parameters
    response.send(Pistache::Http::Code::Ok, products);//tutaj wysyłamy string jsona
  }
 
}


void StoreHandler::sendPrice(Pistache::Rest::Request const& request,
				  Pistache::Http::ResponseWriter response){
  response.send(Pistache::Http::Code::Ok, "Hello "+request.param(":addr").as<std::string>()+ "!\n");
}
