#include "data_structures.hpp"

#include <cassert>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const* argv[]) {
  ds::LinkedList<int> list{};
  list.AddBack(1);
  list.AddBack(2);
  list.AddBack(3);
  list.AddBack(4);
  list.AddBack(5);

  std::cout << "Linked list iterator" << std::endl;

  for (auto begin{ list.begin() }; begin != list.end(); begin++) {
    std::cout << *begin << std::endl;
  }

  for (auto x : list) {
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
