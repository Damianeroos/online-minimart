add_library(
  client
  ../src/client.hpp
  ../src/client.cpp
  )

target_include_directories(client PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
