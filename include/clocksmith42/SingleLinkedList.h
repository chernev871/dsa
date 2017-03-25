#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstdio>

namespace clocksmith42 {

struct Item {
  int data;
};

struct Node {
  Node *next;
  Item item;
};

class SingleLinkedList {
 public:
  SingleLinkedList() : head_(nullptr) {}

  ~SingleLinkedList() { Clear(); }

  void Clear() {
    Node *next = nullptr;
    while (head_ != nullptr) {
      next = head_->next;
      delete head_;
      head_ = next;
    }
  }

  void PushBack(const Item &item) {
    Node *new_node = new Node{nullptr, item};
    Node **last_node = &head_;
    while (*last_node != nullptr) {
      last_node = &(*last_node)->next;
    }
    *last_node = new_node;
  }

  void PushFront(const Item &item) {
    Node *newNode = new Node{nullptr, item};
    newNode->next = head_;
    head_ = newNode;
  }

  void PopFront() {
    if (head_ != nullptr) {
      Node *new_head = head_->next;
      delete head_;
      head_ = new_head;
    }
  }

  void PopBack() {
    if (head_ != nullptr) {
      Node **before_last = &head_;
      Node **last = &head_;
      Node **after_last = &head_;
      while (*after_last != nullptr) {
        before_last = last;
        last = &(*before_last)->next;
        after_last = *last == nullptr ? last : &(*last)->next;
      }
      if (*before_last == head_) {
        PopFront();
      } else {
        delete *last;
        *last = *after_last;
      }
    }
  }

  void Reverse() {
    Node *current = head_;
    Node *next = nullptr;
    Node *new_head = nullptr;
    while (current != nullptr) {
      next = current->next;
      current->next = new_head;
      new_head = current;
      current = next;
    }
    head_ = new_head;
  }

  void Print() const {
    Node *current_node = head_;
    while (current_node != nullptr) {
      printf("%d ", current_node->item.data);
      current_node = current_node->next;
    }
    printf("\n\n");
  }

 private:
  Node *head_;
};

} // namespace clocksmith42

#endif // SINGLE_LINKED_LIST_H