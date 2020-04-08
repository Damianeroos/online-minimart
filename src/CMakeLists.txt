include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)
add_library(
  products
  ../include/products.hpp
  ../src/products.cpp
  )

add_library(
  client
  ../include/client.hpp
  ../src/client.cpp
  )


add_library(
  storeHandler
  ../include/StoreHandler.hpp
  ../src/StoreHandler.cpp
  )

add_library(
  store
  ../include/Store.hpp
  ../src/Store.cpp
  )

add_library(
  online_store
  ../include/online_store.hpp
  ../src/online_store.cpp
  )

target_link_libraries(storeHandler products)
target_link_libraries(online_store client ${CURLPP_LDFLAGS} storeHandler store)
