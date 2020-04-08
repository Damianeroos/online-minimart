#include <gtest/gtest.h>
#include "Store.hpp"

nlohmann::json j =
    "{\"Product\":[{\"name\":\"chleb\",\"price\":450,\"weight\":350},{\"name\":\"piwo\",\"price\":350,\"weight\":500},{\"name\":\"papier toaletowy\",\"price\":10000,\"weight\":100},{\"name\":\"płyn dezynfekujacy Orlen\",\"price\":14000,\"weight\":1500}]}"_json;

TEST(StoreTests, empty_basket) {
  // Given
  Store store;

  // When/Then
  EXPECT_TRUE(store.emptyBasket());
}

TEST(StoreTests, empty_stock) {
  // Given
  Store store;

  // When/Then
  EXPECT_TRUE(store.emptyStock());
}

TEST(StoreTests, setProducts) {
  // Given
  Store store;

  // When/Then
  EXPECT_TRUE(store.emptyStock());
  store.setProducts(j);
  EXPECT_FALSE(store.emptyStock());
}

TEST(StoreTests, add_to_basket) {
  // Given
  Store store;

  // When/Then
  store.setProducts(j);
  EXPECT_FALSE(store.emptyStock());
  EXPECT_TRUE(store.emptyBasket());
  EXPECT_FALSE(store.addToBasket("herbata"));  // no key named piwo in store
  EXPECT_TRUE(store.emptyBasket());
  EXPECT_TRUE(store.addToBasket("chleb"));
  EXPECT_FALSE(store.emptyBasket());
}

TEST(StoreTests, remove_from_basket) {
  // Given
  Store store;

  // When/Then
  store.setProducts(j);
  EXPECT_FALSE(store.emptyStock());
  EXPECT_TRUE(store.emptyBasket());
  EXPECT_TRUE(store.addToBasket("chleb"));
  EXPECT_FALSE(store.emptyBasket());
  EXPECT_FALSE(store.removeFromBasket("piwo"));  // no piwo in the basket
  EXPECT_TRUE(store.removeFromBasket("chleb"));
  EXPECT_TRUE(store.emptyBasket());
}

TEST(StoreTests, get_net_price) {
  // Give
  Store store;

  // When/Then
  store.setProducts(j);
  store.addToBasket("papier toaletowy");
  store.addToBasket("papier toaletowy");
  store.addToBasket("chleb");
  EXPECT_EQ(store.get_price(), 20450);
}

TEST(StoreTests, clearBasket) {
  // Give
  Store store;

  // When/Then
  store.setProducts(j);
  store.addToBasket("papier toaletowy");
  store.addToBasket("papier toaletowy");
  EXPECT_FALSE(store.emptyBasket());
  store.clearBasket();
  EXPECT_TRUE(store.emptyBasket());
}

TEST(StoreTest, clearPrice) {
  // Give
  Store store;

  // When/Then
  store.setProducts(j);
  EXPECT_EQ(store.get_price(), 0);
  store.addToBasket("papier toaletowy");
  store.addToBasket("papier toaletowy");
  EXPECT_GT(store.get_price(), 0);
}
