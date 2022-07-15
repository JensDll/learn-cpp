#include "linked_list.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("My first test", "[linked_list]") {
  ds::LinkedList<int> list{};
  REQUIRE(list.count() == 0);
}
