#include <iostream>

#ifndef LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
#define LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
namespace ds {

template <typename T>
class LinkedList {
 public:
  LinkedList();

  void AddFirst(T value) const;

 private:
  class Node {
   public:
    Node(T value);

    T value;
    Node* next{ nullptr };
    Node* prev{ nullptr };
  };
};

}  // namespace ds

#include "linked_list.inl"

#endif
