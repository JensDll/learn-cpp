#include "data_structures.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <cassert>
#include <iostream>
#include <list>
#include <vector>

int main() {
  fmt::print("Welcome to fmt!\n");
  spdlog::info("Welcome to spdlog!");

  ds::LinkedList<std::string> list{};
  list.AddBack("one");
  list.AddBack("two");
  list.AddBack("three");
  list.AddBack("four");
  list.AddBack("five");

  std::cout << list << " iterator" << std::endl;

  for (auto begin{ list.begin() }; begin != list.end(); begin++) {
    std::cout << *begin << std::endl;
  }

  std::cout << list << " for-each loop" << std::endl;

  for (const auto& x : list) {
    std::cout << x << std::endl;
  }

  std::cout << "Vector iterator" << std::endl;

  std::vector<int> xs{ 1, 2, 3, 4, 5 };

  for (auto begin{ xs.begin() }; begin != xs.end(); ++begin) {
    std::cout << *begin << std::endl;
  }

  std::list<int> ys{ 1, 2, 3, 4, 5 };

  return 0;
}
