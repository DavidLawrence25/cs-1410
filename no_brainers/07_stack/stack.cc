#include "no_brainers/07_stack/stack.h"

namespace rose {

Stack::Stack() {
  top_ = nullptr;
}

Stack::~Stack() {
  while (!IsEmpty()) Pop();
}

// Returns true if the stack has no items.
bool Stack::IsEmpty() {
  return top_ == nullptr;
}

// Pushes the value `data` onto the top of the stack.
void Stack::Push(std::string data) {
  Node *to_add = new Node{data, IsEmpty() ? nullptr : top_};
  top_ = to_add;
}

// Removes the value at the top of the stack.
// Does nothing if the stack is empty.
void Stack::Pop() {
  if (IsEmpty()) return;
  Node *temp = top_;
  top_ = top_->next;
  delete temp;
}

// Returns the value at the top of the stack.
std::string Stack::Peek() {
  return top_->data;
}

std::ostream &operator<<(std::ostream &out, const Stack &stack) {
  Node *current = stack.top_;
  while (current != nullptr) {
    out << current->data << ' ';  // TODO: Remove trailing whitespace.
    current = current->next;
  }
  return out;
}

}  // namespace rose
