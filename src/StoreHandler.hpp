#pragma once

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include "products.hpp"

class StoreHandler {
 public:
  void publish(std::shared_ptr<Pistache::Rest::Router> router);

 private:
  void sendProducts(Pistache::Rest::Request const&,
                    Pistache::Http::ResponseWriter response);
  void sendPrice(Pistache::Rest::Request const&,
                 Pistache::Http::ResponseWriter response);

  products store;
};
