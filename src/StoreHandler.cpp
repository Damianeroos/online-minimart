#include "StoreHandler.hpp"

using namespace Pistache;

void StoreHandler::publish(std::shared_ptr<Pistache::Rest::Router> router) {
  using namespace Pistache::Rest;
  Routes::Get(*router, "/GetProducts",
              Routes::bind(&StoreHandler::sendProducts, this));
  Routes::Get(*router, "/order/:id",
              Routes::bind(&StoreHandler::sendPrice, this));
}

void StoreHandler::sendProducts(Pistache::Rest::Request const& request,
                                Pistache::Http::ResponseWriter response) {
  std::string message;

  if (request.query().as_str().empty()) {
    response.send(Pistache::Http::Code::Ok,
                  store.get().dump());  // tutaj wysyłamy string jsona
  }
}

void StoreHandler::sendPrice(Pistache::Rest::Request const& request,
                             Pistache::Http::ResponseWriter response) {
  int price = request.param(":id").as<int>();
  price += static_cast<int>(price * 0.23);

  response.send(Pistache::Http::Code::Ok, std::to_string(price));
}
