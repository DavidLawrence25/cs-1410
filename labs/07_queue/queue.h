#include <ostream>
#include <string>

#ifndef CS1410_LABS_07QUEUE_QUEUE_H_
#define CS1410_LABS_07QUEUE_QUEUE_H_

namespace rose {

// Represents a node containing a string in a linked list.
struct Node {
  std::string data;
  Node *next;
};

// Represents a FIFO queue of strings.
class Queue {
 public:
  Queue();
  ~Queue();

  // Returns true if there are no items in the queue.
  bool IsEmpty();
  // Appends an item to the back of the queue.
  void Add(std::string data);
  // Removes the item at the front of the queue.
  void Remove();
  // Returns the value of the item at the front of the queue.
  std::string Peek();

  friend std::ostream &operator<<(std::ostream &out, Queue &queue);

 private:
  Node *front_;
};

}  // namespace rose

#endif  // CS1410_LABS_07QUEUE_QUEUE_H_