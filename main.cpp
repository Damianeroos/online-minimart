#include <algorithm>
#include <iostream>
#include <string>
#include "src/online_store.hpp"

using std::cin;
using std::cout;

void help() {
  cout << "posible actions: \n";
  cout << "p         - show avaviable products\n";
  cout << "a <item>  - add item to basket\n";
  cout << "k         - show basket\n";
  cout << "b         - buy items in basket\n";
  cout << "h         - help\n";
  cout << "e         - exit\n";
  cout << "c         - connect to shop server\n";
  cout << "i         - set server addres (default: localhost:1234)\n";
}

void info() {}

int main() {
  online_store store;
  char option;
  std::string url, item, quantity;
  std::vector<std::string>::iterator it;
  int temp;
  bool success=false;

  cout << "\tWELCOME TO ONLINE MINIMART!!!\n";

  if (store.init())
    cout << "Successfully connected to server\n";
  else {
    cout << "Unable to establish a connection to the server\n";
  }

  cout << "Type 'h' for possible actions\n";
  while (1) {
    cout << "(h-help) >> ";
    cin >> option;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option) {
    case 'p':
      cout << (store.getProducts()).dump(2) << std::endl;
      break;
    case 'a':
      cout << "Product name: ";
      std::getline(std::cin,item);
      cout << "Quantity: ";
      
      while(!success){
	success=true;
	cin>>quantity;
	try{
	  temp = std::stoi(quantity);
	}
	catch(const std::invalid_argument& e){
	  std::cerr<<"The quantity has to be an intiger. Try again\n";
	  std::cout<< "Quantity: ";
	    success=false;
	}

      }
	success=false;
        for (int i = 0; i < temp; ++i) {
          if (!store.addToBasket(item)) {
            cout << "No " << item << " in the store\n";
            break;
          }
        }
        break;
      case 'k':
        if (store.emptyBasket())
          cout << "Basket is empty\n";
        else {
          cout << "Basket:\n";
          for (const auto &it : store.getBasket()) cout << it << std::endl;
          cout << "Total items: " << store.getBasket().size() << std::endl;
          cout << "Net price: " << store.get_price() << std::endl;
        }
        break;
      case 'b':
        if (!store.computeGrossPrice()) {
          cout << "Failed to compute final price. Check internet connection\n";
          break;
        }
	if(store.emptyBasket()){
	  cout<< "Empty basket\n";
	  break;
	}
        cout << "Gross price: " << store.getGrossPrice() << std::endl;
        cout << "We accepted your order\n";
        store.clearBasket();
        store.clearPrice();
        break;
      case 'h':
        help();
        break;
      case 'e':
        cout << "Thank you for using our services. We invite you again.\n";
        return 1;  // maybe shotduwn server also?
        break;
      case 'c':
        if (store.init())
          cout << "Successfully connected to server\n";
        else {
          cout << "Unable to establish a connection to the server\n";
        }
        break;
      case 'i':
        cout << "Address: ";
        cin >> url;
        store.setAddr(url);
        break;
      default:
        cout << "Wrong options. Type 'h' for help.\n";
        break;
    }
  }
}
