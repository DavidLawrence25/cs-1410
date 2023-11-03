#include "queue.h"

#include <ostream>
#include <string>

namespace rose {

template <typename T>
Queue<T>::Queue() {
  elements_ = SLinkedList<T>();
}

template <typename T>
Queue<T>::~Queue() {
  elements_.~SLinkedList();
}

// Returns true if the queue has no items.
template <typename T>
bool Queue<T>::IsEmpty() const {
  return elements_.IsEmpty();
}

// Appends an item to the back of the queue.
template <typename T>
void Queue<T>::Add(T data) {
  elements_.Append(data);
}

// Removes the item at the front of the queue.
template <typename T>
void Queue<T>::Remove() {
  elements_.Pop();
}

// Returns the value of the item at the front of the queue.
template <typename T>
T Queue<T>::Peek() const {
  return elements_.PeekHead();
}

template <typename Y>
std::ostream &operator<<(std::ostream &out, const Queue<Y> &queue) {
  Node<Y> *current = queue.elements_.head();
  while (current != nullptr) {
    out << current->data << ' ';  // TODO: Remove trailing whitespace.
    current = current->next;
  }
  return out;
}

}  // namespace rose
