#include "linked_list.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Constructors") {
  SECTION("Default") {
    ds::LinkedList<int> list;

    REQUIRE(list.size() == 0);
  }

  SECTION("Value") {
    ds::LinkedList<int> list{};

    REQUIRE(list.size() == 0);
  }

  SECTION("List") {
    ds::LinkedList<int> list{ 1, 2, 3, 4, 5 };

    REQUIRE(list.size() == 5);
  }

  SECTION("Copy") {
    ds::LinkedList<int> list{ 1, 2, 3, 4, 5 };
    ds::LinkedList<int> copy{ list };

    REQUIRE(list.size() == 5);
    REQUIRE(copy.size() == 5);
  }
}
