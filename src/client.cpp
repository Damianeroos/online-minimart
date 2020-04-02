#include "client.hpp"

bool client::importProducts(nlohmann::json& products) {
  std::string result;
  std::ostringstream response;
  curlpp::Cleanup myCleanup;
  curlpp::Easy myRequest;
  nlohmann::json t_products = products;
  std::string temp_url = url + "/GetProducts";

  try {
    myRequest.setOpt(new curlpp::options::Url(temp_url));
    myRequest.setOpt(new curlpp::options::WriteStream(&response));

    myRequest.perform();
    products = nlohmann::json::parse(response.str());

  } catch (curlpp::RuntimeError& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  catch (curlpp::LogicError& e) {
    std::cerr << e.what() << std::endl;
    return false;
  } catch (nlohmann::json::parse_error& e) {
    products = t_products;
    std::cerr << e.what() << std::endl;
    std::cerr << "Do not get json format from server.\n";
    return false;
  }
  return true;
}

bool client::importFinalPrice(int& price) {
  std::string result;
  std::ostringstream response;
  curlpp::Cleanup myCleanup;
  curlpp::Easy myRequest;
  std::string temp_url = url + "/order/";

  try {
    myRequest.setOpt(
        new curlpp::options::Url(temp_url + std::to_string(price)));
    myRequest.setOpt(new curlpp::options::WriteStream(&response));

    myRequest.perform();
    price = std::stoi(response.str());
  } catch (curlpp::RuntimeError& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  catch (curlpp::LogicError& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

// bool client::importFinalPrice(int& price){
//   curlpp::Cleanup myCleanup;
//   curlpp::Easy myRequest;
//   std::list<std::string> header;
//   std::ostringstream response;
//   std::string gross_price = std::to_string(price);

//   header.push_back("Content-Type: application/json");

//   try{
//     myRequest.setOpt(new curlpp::options::Verbose(true));
//     myRequest.setOpt(new curlpp::options::Url(url+"/order"));
//     myRequest.setOpt(new curlpp::options::HttpHeader(header));
//     myRequest.setOpt(new curlpp::options::PostFields(gross_price));
//     myRequest.setOpt(new
//     curlpp::options::PostFieldSize(gross_price.length()));
//     myRequest.setOpt(new curlpp::options::WriteStream(&response));

//     myRequest.perform();
//     		std::string effURL;
// 		curlpp::infos::EffectiveUrl::get(myRequest, effURL);
// 		std::cout << "Effective URL: " << effURL << std::endl;
//     std::cerr<<response.str()<<std::endl;
//     //    price = std::stoi(response.str());

//   }
//   catch(curlpp::RuntimeError & e)
//     {
//       std::cerr << e.what() << std::endl;
//       return false;
//     }

//   catch(curlpp::LogicError & e)
//     {
//       std::cerr << e.what() << std::endl;
//       return false;
//     }

//   return true;
// }
