#include "s_linked_list.h"

#include <stdlib.h>

namespace rose {

template <typename T>
SLinkedList<T>::SLinkedList() {
  head_ = nullptr;
  length_ = 0;
}

template <typename T>
SLinkedList<T>::~SLinkedList() {
  while (!IsEmpty()) Pop();
}

template <typename T>
Node<T> *SLinkedList<T>::head() {
  return head_;
}

template <typename T>
Node<T> *SLinkedList<T>::tail() {
  Node<T> *current = head_;
  while (current->next != nullptr) current = current->next;
  return current;
}

template <typename T>
size_t SLinkedList<T>::length() {
  return length_;
}

template <typename T>
bool SLinkedList<T>::IsEmpty() {
  return length_ == 0;
}

template <typename T>
bool SLinkedList<T>::Contains(T element) {
  Node<T> *current = head_;
  while (current != nullptr) {
    if (current->data == element) return true;
    current = current->next;
  }
  return false;
}

template <typename T>
void SLinkedList<T>::Push(T element) {
  Node<T> *to_add = new Node<T>{element, head_};
  head_ = to_add;
  ++length_;
}

template <typename T>
void SLinkedList<T>::Insert(T element, size_t i) {
  if (i > length_) return;
  if (i == 0) {
    Push(element);
    return;
  }
  if (i == length_) {
    Append(element);
    return;
  }

  Node<T> *before = head_;
  for (size_t j = 0; j < i - 1; ++j) before = before->next;

  Node<T> *to_add = new Node<T>{element, before->next};
  before->next = to_add;
  ++length_;
}

template <typename T>
void SLinkedList<T>::Append(T element) {
  Node<T> *to_add = new Node<T>{element, nullptr};
  tail()->next = to_add;
  ++length_;
}

template <typename T>
void SLinkedList<T>::Pop() {
  if (IsEmpty()) return;
  Node<T> *old_head = head_;
  head_ = head_->next;
  delete old_head;
  --length_;
}

template <typename T>
void SLinkedList<T>::Remove(T element) {
  Node<T> *before = nullptr;
  Node<T> *to_delete = head_;
  while (true) {
    if (to_delete == nullptr) return;
    if (to_delete->data == element) break;
    before = to_delete;
    to_delete = to_delete->next;
  }
  if (before == nullptr) {
    head_ = head_->next;
  } else {
    before->next = to_delete->next;
  }
  delete to_delete;
  --length_;
}

template <typename T>
void SLinkedList<T>::Remove(size_t i) {
  if (i >= length_) return;
  if (i == 0) {
    Pop();
    return;
  }

  Node<T> *before = head_;
  for (size_t j = 0; j < i - 1; ++j) before = before->next;

  Node<T> *to_delete = before->next;
  before->next = to_delete->next;
  delete to_delete;
  --length_;
}

template <typename T>
T SLinkedList<T>::PeekHead() {
  return IsEmpty() ? NULL : head_->data;
}

template <typename T>
T SLinkedList<T>::PeekTail() {
  return IsEmpty() ? NULL : tail()->data;
}

template <typename T>
void SLinkedList<T>::Reverse() {
  Node<T> *before = nullptr;
  Node<T> *current = head_;
  Node<T> *after = nullptr;
  while (current != nullptr) {
    after = current->next;
    current->next = before;
    before = current;
    current = after;
  }
  head_ = before;
}

}  // namespace rose
