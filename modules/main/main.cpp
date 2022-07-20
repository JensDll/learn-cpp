#include "linked_list.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <vector>

int main() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::info("Main started");

  const ds::linked_list<std::string> list{ "one", "two", "three", "four" };
  ds::linked_list<std::string> other_list{ "foo", "bars" };

  for (auto& value : other_list) {
    fmt::print("{} ", value);
  }

  fmt::print("\n");

  other_list = list;

  for (auto& value : list) {
    fmt::print("{} ", value);
  }

  fmt::print("\n");

  for (auto& value : other_list) {
    fmt::print("{} ", value);
  }

  fmt::print("\n");

  return 0;
}
