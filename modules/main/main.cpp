#include "linked_list.hpp"
#include <fmt/core.h>

int main() {
  ds::linked_list<std::string> list{};
  list.add_back("one");
  list.add_back("two");
  list.add_back("three");
  list.add_back("four");
  list.add_back("five");

  fmt::print("{}\n", list.size());

  for (auto& value : list) {
    fmt::print("{}\n", value);
  }

  return 0;
}
