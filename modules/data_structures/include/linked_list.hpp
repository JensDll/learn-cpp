#include <iostream>

#ifndef LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
#define LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
namespace ds {

template <typename T>
class LinkedList {
 private:
  class Node;
  class Iterator;

 public:
  constexpr int count() const { return m_count; };

  Node& AddFront(T value);
  Node& AddBack(T value);

  Iterator begin() { return Iterator{ m_front }; };
  Iterator end() { return Iterator{ nullptr }; };

 private:
  int m_count{ 0 };
  Node* m_front{ nullptr };
  Node* m_back{ nullptr };

  class Node {
   public:
    Node(T value);

    T value;
    Node* next{ nullptr };
    Node* prev{ nullptr };
  };

  class Iterator {
   public:
    Iterator(Node* pNode) : mp_node{ pNode } {}

    Iterator& operator++() {
      mp_node = mp_node->next;
      return *this;
    }

    Iterator& operator++(int) {
      mp_node = mp_node->next;
      return *this;
    }

    T operator*() { return mp_node->value; }

    bool operator==(const Iterator& other) const {
      return mp_node == other.mp_node;
    }

    bool operator!=(const Iterator& other) const {
      return mp_node != other.mp_node;
    }

   private:
    Node* mp_node;
  };
};

}  // namespace ds

#include "linked_list.inl"

#endif
