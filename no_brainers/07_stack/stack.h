#include <ostream>
#include <string>

#ifndef CS1410_NOBRAINERS_07STACK_STACK_H_
#define CS1410_NOBRAINERS_07STACK_STACK_H_

namespace rose {

// Represents a node in a linked list.
template <typename T>
struct Node {
  T data;
  Node *next;
};

// Represents a LIFO stack of data in memory.
class Stack {
 public:
  Stack();
  ~Stack();

  // Returns true if the stack has no items.
  bool IsEmpty();
  // Pushes the value `data` onto the top of the stack.
  template <typename T>
  void Push(T data);
  // Removes the value at the top of the stack.
  void Pop();
  // Returns the value at the top of the stack.
  template <typename T>
  T Peek();

  friend std::ostream &operator<<(std::ostream out, const Stack &stack);

 private:
  Node<std::string> *top;
};

}

#endif  // CS1410_NOBRAINERS_07STACK_STACK_H_