include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)


add_library(
  products
  ../src/products.hpp
  ../src/products.cpp
  )

add_library(
  client
  ../src/client.hpp
  ../src/client.cpp
  )


add_library(
  storeHandler
  ../src/StoreHandler.hpp
  ../src/StoreHandler.cpp
  )

add_library(
  store
  ../src/Store.cpp
  ../src/Store.hpp
  )


target_link_libraries(storeHandler products)
