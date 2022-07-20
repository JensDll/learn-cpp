#ifndef LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP
#define LEARN_CPP_DATA_STRUCTURES_LINKED_LIST_HPP

#include <iostream>

namespace ds {

template <typename T>
class linked_list {
 private:
  class node;
  class const_iterator;

 public:
  linked_list() = default;
  linked_list(std::initializer_list<T> values);
  linked_list(const linked_list<T>& list);
  linked_list(const linked_list<T>&& list) noexcept;
  ~linked_list();

  [[nodiscard]] constexpr int size() const { return m_size_; }
  [[nodiscard]] constexpr node& first() const { return *m_first_; }
  [[nodiscard]] constexpr node& last() const { return *m_last_; }

  node& add_first(T value);
  node& add_last(T value);
  void remove(node& to_remove);
  void remove_first();
  void remove_last();

  [[nodiscard]] constexpr const_iterator begin() const {
    return const_iterator{ m_first_ };
  }
  [[nodiscard]] constexpr const_iterator end() const {
    return const_iterator{ nullptr };
  }

  linked_list& operator=(linked_list list);
  linked_list& operator=(linked_list&& list) noexcept;
  linked_list& operator=(std::initializer_list<T> values);

 private:
  int m_size_{ 0 };
  node* m_first_{ nullptr };
  node* m_last_{ nullptr };

  class node {
   public:
    explicit node(T value);

    T m_value;
    node* m_next{ nullptr };
    node* m_prev{ nullptr };
  };

  class const_iterator {
   public:
    using value_type = T;
    using pointer_type = const node*;
    using reference_type = const value_type&;
    using difference_type = int;

    explicit const_iterator(pointer_type ptr);

    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);
    reference_type operator*() const;
    bool operator==(const const_iterator& other) const;
    bool operator!=(const const_iterator& other) const;

   private:
    pointer_type m_ptr_;
  };

  template<typename U>
  friend void swap(linked_list<U>& left, linked_list<U>& right) noexcept;  // NOLINT(readability-redundant-declaration)
};

template <typename T>
void swap(linked_list<T>& left, linked_list<T>& right) noexcept {
  using std::swap;

  swap(left.m_size_, right.m_size_);
  swap(left.m_first_, right.m_first_);
  swap(left.m_last_, right.m_last_);
}

}  // namespace ds

// ############## linked_list ##############

// ------- constructors -------

template <typename T>
ds::linked_list<T>::linked_list(std::initializer_list<T> values) {
  std::cout << *this << " IL constructor " << std::endl;

  for (const T& value : values) {
    add_last(value);
  }
}

template <typename T>
ds::linked_list<T>::linked_list(const ds::linked_list<T>& list) {
  std::cout << list << " copy constructor" << std::endl;

  for (const T& value : list) {
    add_last(value);
  }
}

template <typename T>
ds::linked_list<T>::linked_list(const ds::linked_list<T>&& list) noexcept {
  std::cout << list << " move constructor" << std::endl;
}

template <typename T>
ds::linked_list<T>::linked_list::~linked_list() {
  std::cout << *this << " destructor " << std::endl;

  node* current{ m_first_ };

  while (current) {
    const node* prev{ current };
    current = current->m_next;
    delete prev;
  }

  m_size_ = 0;
  m_first_ = nullptr;
  m_last_ = nullptr;
}

// ------- methods -------

template <typename T>
typename ds::linked_list<T>::node& ds::linked_list<T>::add_first(T value) {
  node* new_node{ new node{ value } };

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
typename ds::linked_list<T>::node& ds::linked_list<T>::add_last(T value) {
  node* new_node{ new node{ value } };

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
void ds::linked_list<T>::remove(node& to_remove) {
  if (m_size_ == 0) {
    return;
  }
  
  if (&to_remove == m_first_) {
    remove_first();
  } else if (&to_remove == m_last_) {
    remove_last();
  } else {
    to_remove.m_prev->m_next = to_remove.m_next;
    to_remove.m_next->m_prev = to_remove.m_prev;
    delete &to_remove;
    --m_size_;
  }
}

template <typename T>
void ds::linked_list<T>::remove_first() {
  if (m_size_ == 0) {
    return;
  }

  const node* const first{ m_first_ };

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
void ds::linked_list<T>::remove_last() {
  if (m_size_ == 0) {
    return;
  }

  const node* const last{ m_last_ };

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

// -------  operators -------

template <typename T>
std::ostream& operator<<(std::ostream& out, const ds::linked_list<T>& list) {
  out << "linked_list(size=" << list.size() << ")";
  return out;
}

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(linked_list<T> list) {
  swap(*this, list);
  return *this;
}

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(linked_list&& list) noexcept {
  //std::cout << list << " move assignment" << std::endl;

  return *this;
}

template <typename T>
ds::linked_list<T>& ds::linked_list<T>::operator=(
    std::initializer_list<T> values) {
  std::cout << *this << " IL assignment" << std::endl;

  for (T value : values) {
    add_first(value);
  }

  return *this;
}

// ############## linked_list::node ##############

template <typename T>
ds::linked_list<T>::node::node(T value) : m_value{ std::move(value) } {}

// ############## linked_list::const_iterator ##############

template <typename T>
ds::linked_list<T>::const_iterator::const_iterator(pointer_type ptr)
    : m_ptr_{ ptr } {}

template <typename T>
typename ds::linked_list<T>::const_iterator&
ds::linked_list<T>::const_iterator::operator++() {
  m_ptr_ = m_ptr_->m_next;
  return *this;
}

template <typename T>
typename ds::linked_list<T>::const_iterator
ds::linked_list<T>::const_iterator::operator++(int) {
  const_iterator iter{ *this };
  ++(*this);
  return iter;
}

template <typename T>
typename ds::linked_list<T>::const_iterator&
ds::linked_list<T>::const_iterator::operator--() {
  m_ptr_ = m_ptr_->m_prev;
  return *this;
}

template <typename T>
typename ds::linked_list<T>::const_iterator
ds::linked_list<T>::const_iterator::operator--(int) {
  const_iterator iter{ *this };
  --(*this);
  return iter;
}

template <typename T>
typename ds::linked_list<T>::const_iterator::reference_type
ds::linked_list<T>::const_iterator::operator*() const {
  return m_ptr_->m_value;
}

template <typename T>
bool ds::linked_list<T>::const_iterator::operator==(
    const const_iterator& other) const {
  return m_ptr_ == other.m_ptr_;
}

template <typename T>
bool ds::linked_list<T>::const_iterator::operator!=(
    const const_iterator& other) const {
  return !(*this == other);
}

#endif
