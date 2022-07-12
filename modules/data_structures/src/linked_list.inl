template <typename T>
ds::LinkedList<T>::Node::Node(T value) : value(value) {}

template <typename T>
ds::LinkedList<T>::LinkedList() {
  std::cout << "List constructor" << std::endl;
}

template <typename T>
void ds::LinkedList<T>::AddFirst(T value) const {
  LinkedList<T>::Node node{ value };
  std::cout << "AddFirst " << node.next << std::endl;
}
