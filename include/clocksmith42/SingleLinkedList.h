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

  const Node *Front() const { return head_; }

  Node *Front() { return head_; }

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
      if (head_->next == nullptr) { PopFront(); }
      else {
        Node *before_last = head_;
        Node *last = head_->next;
        while (last->next != nullptr) {
          before_last = last;
          last = last->next;
        }
        delete last;
        before_last->next = nullptr;
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

 private:
  void Clear() {
    Node *next = nullptr;
    while (head_ != nullptr) {
      next = head_->next;
      delete head_;
      head_ = next;
    }
  }
};

} // namespace clocksmith42

#endif // SINGLE_LINKED_LIST_H