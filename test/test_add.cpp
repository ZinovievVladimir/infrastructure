#include <gtest/gtest.h>
#include "way.h"

bool check(int i, int j) {
  char* ch = min_way(i, j);
      int x = 0, y = 0;
      int z = 1;
      for (int i = 0; ch[i] != 0; i++) {
        if (ch[i] == 'N')
          y += z;
        if (ch[i] == 'S')
          y -= z;
        if (ch[i] == 'E')
          x += z;
        if (ch[i] == 'W')
          x -= z;
        z++;
      }
  if ((i == x) && (j == y))
    return true;
  else
    return false;
}

TEST(way, test1) {
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++) {
      bool t = check(i, j);
      EXPECT_TRUE(t);
      t = check(-i, j);
      EXPECT_TRUE(t);
      t = check(i, -j);
      EXPECT_TRUE(t);
      t = check(-i, -j);
      EXPECT_TRUE(t);
    }
}
