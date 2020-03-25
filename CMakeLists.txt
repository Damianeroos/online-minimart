cmake_minimum_required(VERSION 3.10.2)

# set the project name
project(onlineStore)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
set(DO_CLANG_FORMAT clang-format)
set(CLANG_OPT "-i")

add_custom_target(start COMMAND onlineStore)
add_custom_target(format COMMAND
    ${DO_CLANG_FORMAT} ${CLANG_OPT}
  ../json.cpp
  )

# add the executable
add_executable(onlineStore json.cpp)
