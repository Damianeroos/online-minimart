# online-minimart

This is simple application that implement online store.

Functionalities:

-p         - show available products

-a <item>  - add item to basket
  
-k         - show basket

-b         - buy items in basket

-h         - help

-e         - exit

-c         - connect to shop server

-i         - set server addres (default: localhost:1234)

For proper working of the appilcation, the server must be running.Executable main connect and download from the server all products by REST api.Client also send net price to the server, then server compute gross price in gorsz curent and send back to client.
