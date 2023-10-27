#include <ostream>

#include "custom_libraries/s_linked_list.h"

#ifndef CS1410_NOBRAINERS_08STACKTEMPLATE_STACK_H_
#define CS1410_NOBRAINERS_08STACKTEMPLATE_STACK_H_

namespace rose {

// Represents a LIFO stack of data of type `T`.
template <typename T>
class Stack {
 public:
  Stack();
  ~Stack();

  // Returns true if the stack has no items.
  bool IsEmpty();
  // Pushes the value `data` onto the top of the stack.
  void Push(T data);
  // Removes the value at the top of the stack.
  void Pop();
  // Returns the value at the top of the stack.
  T Peek();

  friend std::ostream &operator<<(std::ostream &out, const Stack &stack);

 private:
  SLinkedList<T> elements_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_08STACKTEMPLATE_STACK_H_