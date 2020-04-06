cmake_minimum_required(VERSION 2.8)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(test_store test_Store.cpp)

target_link_libraries(test_store PUBLIC store gtest_main ${GTEST_LIBRARIES})

add_test(NAME test_store COMMAND test_store)
