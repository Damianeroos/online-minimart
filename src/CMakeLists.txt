include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)


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

