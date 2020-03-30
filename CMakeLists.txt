cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# set the project name
project(onlineStore)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
set(DO_CLANG_FORMAT clang-format)
set(CLANG_OPT "-i")

add_custom_target(start COMMAND onlineStore)
add_custom_target(format COMMAND
    ${DO_CLANG_FORMAT} ${CLANG_OPT}
    ../json.cpp
    ../src/client.hpp
    ../src/client.cpp
    ../src/StoreHandler.cpp
    ../src/StoreHandler.hpp
  )

add_subdirectory(src)

include(FindPkgConfig)
pkg_search_module(PISTACHE REQUIRED libpistache>=0.0.2)
include_directories(${PISTACHE_INCLUDE_DIRS})
# add the executable
add_executable(main main.cpp)
add_executable(server server.cpp)
add_executable(json json.cpp)

target_link_libraries(main PUBLIC client
  ${CURLPP_LDFLAGS}
  storeHandler)
target_link_libraries(server PUBLIC  storeHandler ${PISTACHE_LIBRARIES})

#
