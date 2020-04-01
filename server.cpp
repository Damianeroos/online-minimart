#include "src/StoreHandler.hpp"
#include <csignal>

std::function<void(int)> shutdown_handler;
void signal_handler(int signal) { shutdown_handler(signal); }

int main(){
   try{
    Pistache::Address addr("localhost", Pistache::Port(1234));
    auto router = std::make_shared<Pistache::Rest::Router>();    
    auto opts = Pistache::Http::Endpoint::options().threads(1);
    Pistache::Http::Endpoint endpoint(addr);
      
    shutdown_handler = [&endpoint](int) { endpoint.shutdown();
     std::cout << "\nShuting down server"<< std::endl;};
    
    for (auto sig : {SIGHUP, SIGINT, SIGQUIT, SIGTERM})
      std::signal(sig, signal_handler);
 
    std::cout<<"Server is starting...\n";
    endpoint.init(opts);

    auto handler = StoreHandler();
    handler.publish(router);
    endpoint.setHandler(router->handler());
    endpoint.serve();

  }
  catch(std::exception const& e){
    std::cerr << "FATAL ERROR during program execution: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
