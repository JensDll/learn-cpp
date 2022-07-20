#include "linked_list.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <vector>

void print_list(const ds::linked_list<int>& list) {
  for (const auto& value : list) {
    fmt::print("{} ", value);
  }

  fmt::print("\n");
}

ds::linked_list<int> generate_list() {
  ds::linked_list<int> list{ 1, 2, 3, 4 };
  return list;
}

int main() {
  spdlog::info("Main started");

  ds::linked_list<int> list{ 10, 20, 30 };
  list = generate_list();

  print_list(list);
}
