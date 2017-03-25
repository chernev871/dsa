#include "catch.hpp"

#include "clocksmith42/SingleLinkedList.h"

namespace cs42 = clocksmith42;

TEST_CASE("PushBack", "SingleLinkedList") {
  cs42::SingleLinkedList list;
  for (int i = 0; i < 10; ++i) { list.PushBack(cs42::Item{i}); }
  printf("PushBack SingleLinkedList:\n");
  list.Print();

  cs42::Node *front = list.Front();
  int i = 0;
  while (front != nullptr) {
    REQUIRE(front->item.data == i);
    front = front->next;
    ++i;
  }

}

TEST_CASE("PushFront", "SingleLinkedList") {
  cs42::SingleLinkedList list;
  for (int i = 0; i < 10; ++i) { list.PushFront(cs42::Item{i}); }
  printf("PushFront SingleLinkedList:\n");
  list.Print();

  cs42::Node *front = list.Front();
  int i = 9;
  while (front != nullptr) {
    REQUIRE(front->item.data == i);
    front = front->next;
    --i;
  }

}

TEST_CASE("Reverse", "SingleLinkedList") {
  cs42::SingleLinkedList list;
  for (int i = 0; i < 10; ++i) { list.PushBack(cs42::Item{i}); }
  printf("before Reverse SingleLinkedList:\n");
  list.Print();

  list.Reverse();
  printf("after Reverse SingleLinkedList:\n");
  list.Print();

  cs42::Node *front = list.Front();
  int i = 9;
  while (front != nullptr) {
    REQUIRE(front->item.data == i);
    front = front->next;
    --i;
  }

}

TEST_CASE("PopBack", "SingleLinkedList") {
  cs42::SingleLinkedList list;
  for (int i = 0; i < 10; ++i) { list.PushBack(cs42::Item{i}); }
  printf("before PopBack SingleLinkedList:\n");
  list.Print();

  printf("after PopBack SingleLinkedList:\n");
  list.PopBack();
  list.Print();

  cs42::Node *front = list.Front();
  int i = 0;
  while (front != nullptr) {
    REQUIRE(front->item.data == i);
    front = front->next;
    ++i;
  }

  SECTION("Without elements") {
    cs42::SingleLinkedList empty_list;
    REQUIRE_NOTHROW(empty_list.PopBack());
    empty_list.Print();
  }
}

TEST_CASE("PopFront", "SingleLinkedList") {
  cs42::SingleLinkedList list;
  for (int i = 0; i < 10; ++i) { list.PushBack(cs42::Item{i}); }
  printf("before PopFront SingleLinkedList:\n");
  list.Print();

  printf("after PopFront SingleLinkedList:\n");
  list.PopFront();
  list.Print();

  cs42::Node *front = list.Front();
  int i = 1;
  while (front != nullptr) {
    REQUIRE(front->item.data == i);
    front = front->next;
    ++i;
  }

  SECTION("Without elements") {
    cs42::SingleLinkedList empty_list;
    REQUIRE_NOTHROW(empty_list.PopFront());
    empty_list.Print();
  }

}