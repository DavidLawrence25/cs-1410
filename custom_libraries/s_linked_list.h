#include <stdlib.h>

#ifndef CS1410_CUSTOMLIBRARIES_SLINKEDLIST_H_
#define CS1410_CUSTOMLIBRARIES_SLINKEDLIST_H_

namespace rose {

template <typename T>
struct Node {
  T data;
  Node *next;
};

template <typename T>
class SLinkedList {
 public:
  SLinkedList();
  ~SLinkedList();

  Node<T> *head();
  Node<T> *tail();
  size_t length();

  bool IsEmpty();
  bool Contains(T element);
  void Push(T element);
  void Insert(T element, size_t i);
  void Append(T element);
  void Pop();
  void Remove(T element);
  void Remove(size_t i);
  T PeekHead();
  T PeekTail();
  void Reverse();

 private:
  Node<T> *head_;
  size_t length_;
};

}  // namespace rose

#endif  // CS1410_CUSTOMLIBRARIES_LINKEDLIST_H_
