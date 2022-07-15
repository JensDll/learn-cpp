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
    Iterator(Node* a_node) : m_node{ a_node } {}

    Iterator& operator++() {
      m_node = m_node->next;
      return *this;
    }

    Iterator& operator++(int) {
      m_node = m_node->next;
      return *this;
    }

    T operator*() { return m_node->value; }

    bool operator==(const Iterator& other) const {
      return m_node == other.m_node;
    }

    bool operator!=(const Iterator& other) const {
      return m_node != other.m_node;
    }

   private:
    Node* m_node;
  };
};

template <typename T>
LinkedList<T>::Node::Node(T a_value) : value{ a_value } {}

template <typename T>
typename LinkedList<T>::Node& LinkedList<T>::AddFront(T a_value) {
  Node* node{ new Node{ a_value } };

  if (m_count == 0) {
    m_front = node;
    m_back = node;
  } else {
    node->next = m_front;
    m_front->prev = node;
    m_front = node;
  }

  ++m_count;

  return *node;
}

template <typename T>
typename LinkedList<T>::Node& LinkedList<T>::AddBack(T a_value) {
  Node* node{ new Node{ a_value } };

  if (m_count == 0) {
    m_front = node;
    m_back = node;
  } else {
    node->prev = m_back;
    m_back->next = node;
    m_back = node;
  }

  ++m_count;

  return *node;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& a_list) {
  out << "LinkedList(" << a_list.count() << ")";
  return out;
}

}  // namespace ds

#endif
