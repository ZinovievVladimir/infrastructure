#include <gtest/gtest.h>
#include "Algs.h"

TEST(edge, can_create_edge) {
  ASSERT_NO_THROW(edge a);
  ASSERT_NO_THROW(edge a(1, 2, 3));
}

TEST(edge, can_compare) {
  edge a(1, 2, 3);
  edge b(4, 5, 6);
  ASSERT_NO_THROW(a > b);
  ASSERT_NO_THROW(a < b);
}

TEST(edge, compare_is_right) {
  edge a(1, 2, 3);
  edge b(4, 5, 6);
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(a > b);
}
