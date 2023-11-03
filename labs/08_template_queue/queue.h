#include <ostream>
#include <string>

#include "custom_libraries/s_linked_list.h"

#ifndef CS1410_LABS_08QUEUETEMPLATE_QUEUE_H_
#define CS1410_LABS_08QUEUETEMPLATE_QUEUE_H_

namespace rose {

// Represents a FIFO queue of data of type `T`.
template <typename T>
class Queue {
 public:
  Queue();
  ~Queue();

  // Returns true if there are no items in the queue.
  bool IsEmpty() const;
  // Appends an item to the back of the queue.
  void Add(T data);
  // Removes the item at the front of the queue.
  void Remove();
  // Returns the value of the item at the front of the queue.
  T Peek() const;

  template <typename Y>
  friend std::ostream &operator<<(std::ostream &out, const Queue<Y> &queue);

 private:
  SLinkedList<T> elements_;
};

}  // namespace rose

#include "queue.cc"

#endif  // CS1410_LABS_08QUEUETEMPLATE_QUEUE_H_
