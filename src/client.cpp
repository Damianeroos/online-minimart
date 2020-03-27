#include "client.hpp"

bool client::getProducts(nlohmann::json& arg){
  std::string result;
  std::ostringstream response;
  curlpp::Cleanup myCleanup;
  curlpp::Easy myRequest;

  try
    {
      myRequest.setOpt(new curlpp::options::Url(url));
      myRequest.setOpt(new curlpp::options::WriteStream(&response));

      myRequest.perform();

      arg = nlohmann::json::parse(response.str());


    }
  catch(curlpp::RuntimeError & e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }

  catch(curlpp::LogicError & e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }
  catch(nlohmann::json::parse_error & e)
    {
      arg = "";
      std::cerr<<e.what()<<std::endl;
      std::cerr<<"Do not get json format from server.\n";
      return false;
    }
  return true;
}

bool client::getFinalPrice(int& price){
  curlpp::Cleanup myCleanup;
  curlpp::Easy myRequest;
  std::list<std::string> header;
  std::ostringstream response;
  std::string gross_price = std::to_string(price);
  
  header.push_back("Content-Type: application/json");

  try{
    myRequest.setOpt(new curlpp::options::Url(url));
    myRequest.setOpt(new curlpp::options::HttpHeader(header));
    myRequest.setOpt(new curlpp::options::PostFields(gross_price));
    myRequest.setOpt(new curlpp::options::PostFieldSize(gross_price.length()));
    myRequest.setOpt(new curlpp::options::WriteStream(&response));

    myRequest.perform();
    price = std::stoi(response.str());
    
  }
  catch(curlpp::RuntimeError & e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }

  catch(curlpp::LogicError & e)
    {
      std::cerr << e.what() << std::endl;
      return false;
    }
  
  return true;
}
