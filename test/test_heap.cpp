#include <gtest/gtest.h>
#include <vector>
#include "heap2.h"

using std::vector;
using std::make_pair;

TEST(Heap, can_create) {
  ASSERT_NO_THROW(heap2<int>());
}

TEST(Heap, can_add) {
  heap2<int> t;
  ASSERT_NO_THROW(t.add(4));
  ASSERT_NO_THROW(t.add(2));
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap, can_insert_in_empty_heap) {
  heap2<int> t;
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap, can_find_min) {
  heap2<int> t;
  t.add(1);
  ASSERT_NO_THROW(t.min());
}

TEST(Heap, find_min_correctly) {
  heap2<int> t;
  t.add(1);
  EXPECT_EQ(t.min(), 1);
}

TEST(Heap, throw_when_try_min_without_node) {
  heap2<int> t;
  ASSERT_ANY_THROW(t.min());
}

TEST(Heap, throw_when_try_delete_min_without_node) {
  heap2<int> t;
  ASSERT_ANY_THROW(t.delmin());
}

TEST(Heap, can_delete_min) {
  heap2<int> t;
  t.add(4);
  t.add(1);
  ASSERT_NO_THROW(t.delmin());
}

TEST(Heap, can_delete_head) {
  heap2<int> t;
  t.add(4);
  ASSERT_NO_THROW(t.delmin());
}
