#include "data_structures.hpp"

#include <cassert>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const* argv[]) {
  std::cout << "Hello, World!" << std::endl;

  ds::LinkedList<int> list{};
  list.AddFirst(10);

  std::vector<int> xs{ 1, 2, 3, 4, 5 };
  std::list<int> ys{ 1, 2, 3, 4, 5 };

  return 0;
}
