#include <gtest/gtest.h>
#include <mularr.h>

TEST(mularr, rightMul) {
  int a[] = { 1, 2, 3, 4, 2};
  int b[] = { 48, 24, 16, 12, 24};

  int* c = multip(a, 5);

  for (int i = 0; i < 5; i++)
    EXPECT_EQ(c[i], b[i]);
}

TEST(mularr, oneElem) {
  int a[] = { 8 };

  int* c = multip(a, 1);

  EXPECT_EQ(c[0], 1);
}

TEST(mularr, nulElem) {
  int a[] = { 8 };

  int* c = multip(a, 0);

  EXPECT_EQ(c, nullptr);
}

TEST(mularr, nullpt) {
  int* a = nullptr;

  int* c = multip(a, 1);

  EXPECT_EQ(c, nullptr);
}
