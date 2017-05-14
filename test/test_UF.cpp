#include <gtest/gtest.h>
#include "UF.h"

TEST(union_find, can_create) {
  UF a;
  UF b(10);
}

TEST(union_find, throw_when_create_with_bad_size) {
  ASSERT_ANY_THROW(UF a(-2));
  ASSERT_ANY_THROW(UF a(0));
}

TEST(union_find, throw_when_find_with_bad_pos) {
  UF a(2);
  ASSERT_ANY_THROW(a.Find(-2));
  ASSERT_ANY_THROW(a.Find(4));
}

TEST(union_find, throw_when_union_with_bad_pos) {
  UF a(2);
  ASSERT_ANY_THROW(a.Union(-2, 1));
  ASSERT_ANY_THROW(a.Union(1, -2));
  ASSERT_ANY_THROW(a.Union(4, 1));
  ASSERT_ANY_THROW(a.Union(1, 4));
}

TEST(union_find, can_find) {
  UF a(2);
  ASSERT_NO_THROW(a.Find(1));
}

TEST(union_find, can_union) {
  UF a(2);
  ASSERT_NO_THROW(a.Union(0, 1));
}

TEST(union_find, find_is_right) {
  UF a(2);
  EXPECT_EQ(a.Find(1), 1);
}

TEST(union_find, can_all_in_one) {
  UF a(2);
  ASSERT_NO_THROW(a.all_in_one());
}

TEST(union_find, not_all_in_one_is_right) {
  UF a(2);
  EXPECT_FALSE(a.all_in_one());
  a.Union(0, 1);
  EXPECT_TRUE(a.all_in_one());
}
