#include "linked_list.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <vector>

void print_list(const ds::LinkedList<int>& list) {
  for (const auto& value : list) {
    fmt::print("{} ", value);
  }

  fmt::print("\n");
}

ds::LinkedList<int> generate_list() {
  ds::LinkedList<int> list{ 1, 2, 3, 4 };
  return list;
}

int main() {
  spdlog::info("Main started");

  const ds::LinkedList<int> list{ 10, 20, 30 };

  print_list(list);

  std::vector<int> vec{ 1, 2, 3, 4 };
}
