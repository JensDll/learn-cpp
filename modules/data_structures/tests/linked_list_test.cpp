#include "linked_list.hpp"

#include <catch2/catch_test_macros.hpp>

SCENARIO("Linked list can be can be sized and resized") {
  GIVEN("Default initialization") {
    ds::linked_list<int> list;

    THEN("The size starts at 0") { REQUIRE(list.size() == 0); }
  }

  GIVEN("Value / Zero initialization") {
    ds::linked_list<int> list{};

    THEN("The size starts at 0") { REQUIRE(list.size() == 0); }
  }

  GIVEN("List initialization") {
    ds::linked_list<int> list{ 1, 2, 3, 4, 5 };
    ds::linked_list<int> foo{ list };

    THEN("The size starts at the size of the std::initializer_list") {
      REQUIRE(list.size() == 5);
    }
  }

  GIVEN("Copy initialization with std::initializer_list") {
    ds::linked_list<int> list;
    list = { 1, 2, 3, 4, 5 };

    THEN("The size starts at the size of the std::initializer_list") {
      REQUIRE(list.size() == 5);
    }
  }
}
