#include "stack.h"

#include <ostream>

namespace rose {

template <typename T>
Stack<T>::Stack() {
  elements_ = SLinkedList<T>();
}

template <typename T>
Stack<T>::~Stack() {
  elements_.~SLinkedList();
}

// Returns true if the stack has no items.
template <typename T>
bool Stack<T>::IsEmpty() {
  return elements_.IsEmpty();
}

// Pushes the value `data` onto the top of the stack.
template <typename T>
void Stack<T>::Push(T data) {
  elements_.Push(data);
}

// Removes the value at the top of the stack.
// Does nothing if the stack is empty.
template <typename T>
void Stack<T>::Pop() {
  elements_.Pop();
}

// Returns the value at the top of the stack.
template <typename T>
T Stack<T>::Peek() {
  return elements_.PeekHead();
}

template <typename Y>
std::ostream &operator<<(std::ostream &out, const Stack<Y> &stack) {
  Node<Y> *current = stack.elements_.head();
  while (current != nullptr) {
    out << current->data << ' ';  // TODO: Remove trailing whitespace.
    current = current->next;
  }
  return out;
}

}  // namespace rose
