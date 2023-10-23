#include "queue.h"

#include <ostream>
#include <string>

namespace rose {

Queue::Queue() {
  front_ = nullptr;
}

Queue::~Queue() {
  while (!IsEmpty()) Remove();
}

// Returns true if the queue has no items.
bool Queue::IsEmpty() {
  return front_ == nullptr;
}

// Appends an item to the back of the queue.
void Queue::Add(std::string data) {
  Node *to_add = new Node{data, nullptr};
  if (IsEmpty()) {
    front_ = to_add;
    return;
  }

  Node *back = front_;
  while (back->next != nullptr) back = back->next;  // Bring `back` to the back.
  back->next = to_add;
}

// Removes the item at the front of the queue.
void Queue::Remove() {
  if (IsEmpty()) return;
  Node *temp = front_;
  front_ = front_->next;
  delete temp;
}

// Returns the value of the item at the front of the queue.
std::string Queue::Peek() {
  return front_->data;
}

std::ostream &operator<<(std::ostream &out, Queue &queue) {
  Node *current = queue.front_;
  while (current != nullptr) {
    out << current->data << ' ';  // TODO: Remove trailing whitespace.
    current = current->next;
  }
  return out;
}

}  // namespace rose
