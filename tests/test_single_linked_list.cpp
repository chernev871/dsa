#include "catch.hpp"

#include "clocksmith42/SingleLinkedList.h"

namespace cs42 = clocksmith42;

TEST_CASE("push_back", "SingleLinkedList") {

  cs42::SingleLinkedList list;
  for (int i = 0; i < 100; ++i) {
    list.PushBack(cs42::Item{i});
  }

  REQUIRE(1 == 0);
}
