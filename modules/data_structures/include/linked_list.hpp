#ifndef LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
#define LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP

#include <iostream>

namespace ds {

template <typename T>
class linked_list {
 private:
  class node;
  class iterator;

 public:
  linked_list() = default;
  linked_list(std::initializer_list<T> values);
  linked_list(const linked_list<T>& list);
  linked_list(const linked_list<T>&& list) noexcept;
  ~linked_list();

  [[nodiscard]] constexpr int size() const;

  node& add_front(T value);
  node& add_back(T value);

  iterator begin();
  iterator end();

  linked_list& operator=(const linked_list& list);
  linked_list& operator=(linked_list&& list) noexcept;
  linked_list& operator=(std::initializer_list<T> values);

 private:
  int m_size_{ 0 };
  node* m_front_{ nullptr };
  node* m_back_{ nullptr };

  class node {
   public:
    explicit node(T value);

    T m_value;
    node* m_next{ nullptr };
    node* m_prev{ nullptr };
  };

  class iterator {
   public:
    using value_type = T;
    using pointer_type = node*;
    using reference_type = value_type&;

    explicit iterator(pointer_type ptr);

    iterator& operator++();
    iterator& operator++(int);
    iterator& operator--();
    iterator& operator--(int);
    reference_type operator*();
    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;

   private:
    pointer_type m_ptr_;
  };
};

}  // namespace ds

// ####################### Constructors #######################

template <typename T>
ds::linked_list<T>::linked_list(std::initializer_list<T> values) {
  std::cout << "linked_list initializer list constructor" << std::endl;
}

template <typename T>
ds::linked_list<T>::linked_list(const ds::linked_list<T>& list) {
  std::cout << "linked_list copy constructor" << std::endl;
}

template <typename T>
ds::linked_list<T>::linked_list(const ds::linked_list<T>&& list) noexcept {
  std::cout << "linked_list move constructor" << std::endl;
}

template <typename T>
ds::linked_list<T>::~linked_list() {
  std::cout << "linked_list destructor" << std::endl;
}

template <typename T>
ds::linked_list<T>::node::node(T value) : m_value{ value } {}

template <typename T>
ds::linked_list<T>::iterator::iterator(pointer_type ptr) : m_ptr_{ ptr } {}

// ####################### Methods #######################

template <typename T>
constexpr int ds::linked_list<T>::size() const {
  return m_size_;
}

template <typename T>
typename ds::linked_list<T>::iterator ds::linked_list<T>::begin() {
  return iterator{ m_front_ };
}

template <typename T>
typename ds::linked_list<T>::iterator ds::linked_list<T>::end() {
  return iterator{ m_back_ };
}

template <typename T>
typename ds::linked_list<T>::node& ds::linked_list<T>::add_front(T value) {
  node* new_node{ new node{ value } };

  if (m_size_ == 0) {
    m_front_ = new_node;
    m_back_ = new_node;
  } else {
    new_node->m_next = m_front_;
    m_front_->m_prev = new_node;
    m_front_ = new_node;
  }

  ++m_size_;

  return *new_node;
}

template <typename T>
typename ds::linked_list<T>::node& ds::linked_list<T>::add_back(T value) {
  node* new_node{ new node{ value } };

  if (m_size_ == 0) {
    m_front_ = new_node;
    m_back_ = new_node;
  } else {
    new_node->m_prev = m_back_;
    m_back_->m_next = new_node;
    m_back_ = new_node;
  }

  ++m_size_;

  return *new_node;
}

// ####################### Operators #######################

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(const linked_list& list) {
  std::cout << "linked_list copy assignment operator" << std::endl;

  return *this;
}

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(linked_list&& list) noexcept {
  std::cout << "linked_list move assignment operator" << std::endl;

  return *this;
}

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(
    std::initializer_list<T> values) {
  std::cout << "linked_list initializer list assignment operator" << std::endl;

  return *this;
}

template <typename T>
typename ds::linked_list<T>::iterator&
ds::linked_list<T>::iterator::operator++() {
  m_ptr_ = m_ptr_->m_next;
  return *this;
}

template <typename T>
typename ds::linked_list<T>::iterator& ds::linked_list<T>::iterator::operator++(
    int) {
  iterator iter{ *this };
  ++(*this);
  return iter;
}

template <typename T>
typename ds::linked_list<T>::iterator&
ds::linked_list<T>::iterator::operator--() {
  m_ptr_ = m_ptr_->m_prev;
  return *this;
}

template <typename T>
typename ds::linked_list<T>::iterator& ds::linked_list<T>::iterator::operator--(
    int) {
  iterator iter{ *this };
  --(*this);
  return iter;
}

template <typename T>
typename ds::linked_list<T>::iterator::reference_type
ds::linked_list<T>::iterator::operator*() {
  return m_ptr_->m_value;
}

template <typename T>
bool ds::linked_list<T>::iterator::operator==(const iterator& other) const {
  return m_ptr_ == other.m_ptr_;
}

template <typename T>
bool ds::linked_list<T>::iterator::operator!=(const iterator& other) const {
  return m_ptr_ != other.m_ptr_;
}

#endif
