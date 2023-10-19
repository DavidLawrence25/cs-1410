#include <ostream>
#include <string>

#ifndef CS1410_NOBRAINERS_07STACK_STACK_H_
#define CS1410_NOBRAINERS_07STACK_STACK_H_

namespace rose {

// Represents a node containing a string in a linked list.
struct Node {
  std::string data;
  Node *next;
};

// Represents a LIFO stack of strings.
class Stack {
 public:
  Stack();
  ~Stack();

  // Returns true if the stack has no items.
  bool IsEmpty();
  // Pushes the value `data` onto the top of the stack.
  void Push(std::string data);
  // Removes the value at the top of the stack.
  void Pop();
  // Returns the value at the top of the stack.
  std::string Peek();

  friend std::ostream &operator<<(std::ostream &out, const Stack &stack);

 private:
  Node *top_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_07STACK_STACK_H_