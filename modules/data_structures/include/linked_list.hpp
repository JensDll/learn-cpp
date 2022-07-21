#ifndef LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
#define LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP

#include <iostream>

namespace ds {

template <typename T>
class LinkedList {
 private:
  class Node;
  class ConstIterator;

 public:
  LinkedList() = default;
  LinkedList(std::initializer_list<T> values);
  LinkedList(const LinkedList<T>& other);
  LinkedList(LinkedList<T>&& temp) noexcept;
  ~LinkedList();

  [[nodiscard]] constexpr int size() const { return m_size_; }
  [[nodiscard]] constexpr Node& first() const { return *m_first_; }
  [[nodiscard]] constexpr Node& last() const { return *m_last_; }

  Node& add_first(T value);
  Node& add_last(T value);
  void remove(Node& node);
  void remove_first();
  void remove_last();

  [[nodiscard]] constexpr ConstIterator begin() const {
    return ConstIterator{ m_first_ };
  }
  [[nodiscard]] constexpr ConstIterator end() const {
    return ConstIterator{ nullptr };
  }

  LinkedList& operator=(const LinkedList& other) noexcept;
  LinkedList& operator=(LinkedList&& temp) noexcept;
  LinkedList& operator=(std::initializer_list<T> values);

 private:
  int m_size_{ 0 };
  Node* m_first_{ nullptr };
  Node* m_last_{ nullptr };

  class Node {
   public:
    explicit Node(T value);

    T m_value;
    Node* m_next{ nullptr };
    Node* m_prev{ nullptr };
  };

  class ConstIterator {
   public:
    using ValueType = T;
    using PointerType = const Node*;
    using ReferenceType = const ValueType&;
    using DifferenceType = int;

    explicit ConstIterator(PointerType ptr);

    ConstIterator& operator++();
    ConstIterator operator++(int);
    ConstIterator& operator--();
    ConstIterator operator--(int);
    ReferenceType operator*() const;
    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;

   private:
    PointerType m_ptr_;
  };

  template <typename U>
  // NOLINTNEXTLINE(readability-redundant-declaration)
  friend void swap(LinkedList<U>& left, LinkedList<U>& right) noexcept;
};

template <typename U>
void swap(LinkedList<U>& left, LinkedList<U>& right) noexcept {
  using std::swap;

  swap(left.m_size_, right.m_size_);
  swap(left.m_first_, right.m_first_);
  swap(left.m_last_, right.m_last_);
}

}  // namespace ds

// ############## linked_list ##############

template <typename T>
ds::LinkedList<T>::LinkedList(std::initializer_list<T> values) {
  std::cout << *this << " list constructor " << std::endl;

  for (const T& value : values) {
    add_last(value);
  }
}

template <typename T>
ds::LinkedList<T>::LinkedList(const ds::LinkedList<T>& other) {
  std::cout << other << " copy constructor" << std::endl;

  for (const T& value : other) {
    add_last(value);
  }
}

template <typename T>
ds::LinkedList<T>::LinkedList(ds::LinkedList<T>&& temp) noexcept {
  std::cout << temp << " move constructor" << std::endl;

  swap(*this, temp);
}

template <typename T>
ds::LinkedList<T>::LinkedList::~LinkedList() {
  std::cout << *this << " destructor " << std::endl;

  Node* current{ m_first_ };

  while (current) {
    const Node* prev{ current };
    current = current->m_next;
    delete prev;
  }
}

template <typename T>
typename ds::LinkedList<T>::Node& ds::LinkedList<T>::add_first(T value) {
  Node* new_node{ new Node{ value } };

  if (m_size_ == 0) {
    m_first_ = new_node;
    m_last_ = new_node;
  } else {
    new_node->m_next = m_first_;
    m_first_->m_prev = new_node;
    m_first_ = new_node;
  }

  ++m_size_;

  return *new_node;
}

template <typename T>
typename ds::LinkedList<T>::Node& ds::LinkedList<T>::add_last(T value) {
  Node* new_node{ new Node{ value } };

  if (m_size_ == 0) {
    m_first_ = new_node;
    m_last_ = new_node;
  } else {
    new_node->m_prev = m_last_;
    m_last_->m_next = new_node;
    m_last_ = new_node;
  }

  ++m_size_;

  return *new_node;
}

template <typename T>
void ds::LinkedList<T>::remove(Node& node) {
  if (m_size_ == 0) {
    return;
  }

  if (&node == m_first_) {
    remove_first();
  } else if (&node == m_last_) {
    remove_last();
  } else {
    node.m_prev->m_next = node.m_next;
    node.m_next->m_prev = node.m_prev;
    delete &node;
    --m_size_;
  }
}

template <typename T>
void ds::LinkedList<T>::remove_first() {
  if (m_size_ == 0) {
    return;
  }

  const Node* const first{ m_first_ };

  if (m_size_ == 1) {
    m_first_ = nullptr;
    m_last_ = nullptr;
  } else {
    m_first_ = m_first_->m_next;
    m_first_->m_prev = nullptr;
  }

  delete first;

  --m_size_;
}

template <typename T>
void ds::LinkedList<T>::remove_last() {
  if (m_size_ == 0) {
    return;
  }

  const Node* const last{ m_last_ };

  if (m_size_ == 1) {
    m_first_ = nullptr;
    m_last_ = nullptr;
  } else {
    m_last_ = m_last_->m_prev;
    m_last_->m_next = nullptr;
  }

  delete last;

  --m_size_;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ds::LinkedList<T>& list) {
  out << "linked_list(size=" << list.size() << ")";
  return out;
}

template <typename T>
// NOLINTNEXTLINE(bugprone-unhandled-self-assignment)
ds::LinkedList<T>& ds::LinkedList<T>::operator=(
    const LinkedList<T>& other) noexcept {
  std::cout << other << " copy assignment" << std::endl;

  LinkedList<T> copy{ other };
  swap(*this, copy);
  return *this;
}

template <typename T>
ds::LinkedList<T>& ds::LinkedList<T>::operator=(LinkedList<T>&& temp) noexcept {
  std::cout << temp << " move assignment" << std::endl;

  swap(*this, temp);
  return *this;
}

template <typename T>
ds::LinkedList<T>& ds::LinkedList<T>::operator=(
    std::initializer_list<T> values) {
  std::cout << *this << " list assignment" << std::endl;

  for (T value : values) {
    add_first(value);
  }

  return *this;
}

// ############## linked_list::node ##############

template <typename T>
ds::LinkedList<T>::Node::Node(T value) : m_value{ std::move(value) } {}

// ############## linked_list::const_iterator ##############

template <typename T>
ds::LinkedList<T>::ConstIterator::ConstIterator(PointerType ptr)
    : m_ptr_{ ptr } {}

template <typename T>
typename ds::LinkedList<T>::ConstIterator&
ds::LinkedList<T>::ConstIterator::operator++() {
  m_ptr_ = m_ptr_->m_next;
  return *this;
}

template <typename T>
typename ds::LinkedList<T>::ConstIterator
ds::LinkedList<T>::ConstIterator::operator++(int) {
  ConstIterator iter{ *this };
  ++(*this);
  return iter;
}

template <typename T>
typename ds::LinkedList<T>::ConstIterator&
ds::LinkedList<T>::ConstIterator::operator--() {
  m_ptr_ = m_ptr_->m_prev;
  return *this;
}

template <typename T>
typename ds::LinkedList<T>::ConstIterator
ds::LinkedList<T>::ConstIterator::operator--(int) {
  ConstIterator iter{ *this };
  --(*this);
  return iter;
}

template <typename T>
typename ds::LinkedList<T>::ConstIterator::ReferenceType
ds::LinkedList<T>::ConstIterator::operator*() const {
  return m_ptr_->m_value;
}

template <typename T>
bool ds::LinkedList<T>::ConstIterator::operator==(
    const ConstIterator& other) const {
  return m_ptr_ == other.m_ptr_;
}

template <typename T>
bool ds::LinkedList<T>::ConstIterator::operator!=(
    const ConstIterator& other) const {
  return !(*this == other);
}

#endif
