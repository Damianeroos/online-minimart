#include <gtest/gtest.h>
#include <src/client.hpp>

TEST(clientTest, test){
  // Given
  client c;
  nlohmann::json j;

  // When/Then
  EXPECT_FALSE(c.importProducts(j));

}

