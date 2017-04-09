#include <gtest/gtest.h>
#include <vector>
#include "heap7.h"

using std::vector;
using std::make_pair;

TEST(Heap7, can_create) {
  ASSERT_NO_THROW(heap7<int>());
}

TEST(Heap7, can_add) {
  heap7<int> t;
  ASSERT_NO_THROW(t.add(4));
  ASSERT_NO_THROW(t.add(2));
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap7, can_insert_in_empty_heap) {
  heap7<int> t;
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap7, can_find_min) {
  heap7<int> t;
  t.add(1);
  ASSERT_NO_THROW(t.min());
}

TEST(Heap7, find_min_correctly) {
  heap7<int> t;
  t.add(1);
  EXPECT_EQ(t.min(), 1);
}

TEST(Heap7, throw_when_try_min_without_node) {
  heap7<int> t;
  ASSERT_ANY_THROW(t.min());
}

TEST(Heap7, throw_when_try_delete_min_without_node) {
  heap7<int> t;
  ASSERT_ANY_THROW(t.delmin());
}

TEST(Heap7, can_delete_min) {
  heap7<int> t;
  t.add(4);
  t.add(1);
  ASSERT_NO_THROW(t.delmin());
}

TEST(Heap7, can_delete_head) {
  heap7<int> t;
  t.add(4);
  ASSERT_NO_THROW(t.delmin());
}
