#include <gtest/gtest.h>
#include <vector>
#include "avltree.h"

using std::vector;
using std::make_pair;

TEST(AVLtree, can_create1) {
  ASSERT_NO_THROW(avltree<int>());
}

TEST(AVLtree, can_create2) {
  ASSERT_NO_THROW(avltree<int>(4));
}

TEST(AVLtree, can_insert) {
  avltree<int> t;
  ASSERT_NO_THROW(t.ins(4));
  ASSERT_NO_THROW(t.ins(2));
  ASSERT_NO_THROW(t.ins(1));
}

TEST(AVLtree, can_insert_in_empty_tree) {
  avltree<int> t;
  ASSERT_NO_THROW(t.ins(1));
}

TEST(AVLtree, throw_when_try_insert_exist_node) {
  avltree<int> t(5);
  ASSERT_ANY_THROW(t.ins(5));
}

TEST(AVLtree, can_find_min) {
  avltree<int> t;
  t.ins(1);
  ASSERT_NO_THROW(t.min());
}

TEST(AVLtree, find_min_correctly) {
  avltree<int> t;
  t.ins(1);
  EXPECT_EQ(t.min(), 1);
}

TEST(AVLtree, throw_when_try_min_without_node) {
  avltree<int> t;
  ASSERT_ANY_THROW(t.min());
}

TEST(AVLtree, throw_when_try_delete_min_without_node) {
  avltree<int> t;
  ASSERT_ANY_THROW(t.delmin());
}

TEST(AVLtree, can_delete_min) {
  avltree<int> t;
  t.ins(4);
  t.ins(1);
  ASSERT_NO_THROW(t.delmin());
}

TEST(AVLtree, can_delete_head) {
  avltree<int> t;
  t.ins(4);
  ASSERT_NO_THROW(t.delmin());
}
