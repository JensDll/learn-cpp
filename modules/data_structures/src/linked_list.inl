#include "linked_list.hpp"

template <typename T>
ds::LinkedList<T>::Node::Node(T value) : value{ value } {}

template <typename T>
ds::LinkedList<T>::Node& ds::LinkedList<T>::AddFront(T value) {
  Node* node{ new Node{ value } };

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
ds::LinkedList<T>::Node& ds::LinkedList<T>::AddBack(T value) {
  Node* node{ new Node{ value } };

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
std::ostream& operator<<(std::ostream& out, const ds::LinkedList<T>& list) {
  out << "LinkedList(" << list.count() << ")" << std::endl;
  return out;
}
