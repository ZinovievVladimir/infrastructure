#include <gtest/gtest.h>
#include <vector>
#include "tk.h"
#define n 3

using std::pair;
using std::vector;
using std::cout;
using std::make_pair;

TEST(tk, test1) {
  vector< pair< int, int > > p;
  p.push_back(make_pair(0, 1));
  p.push_back(make_pair(1, 2));
  p.push_back(make_pair(0, 2));
  vector < int > ret = tk(p, n);

  vector < int > r;
  r.push_back(0);
  r.push_back(1);
  r.push_back(2);

  EXPECT_EQ(ret, r);
}

TEST(tk, test2) {
  vector< pair< int, int > > p2;
  p2.push_back(make_pair(0, 1));
  p2.push_back(make_pair(1, 2));
  p2.push_back(make_pair(0, 2));
  p2.push_back(make_pair(0, 3));
  p2.push_back(make_pair(2, 3));
  vector < int > ret2 = tk(p2, n + 1);

  vector < int > r;
  r.push_back(0);
  r.push_back(1);
  r.push_back(2);
  r.push_back(1);

  EXPECT_EQ(ret2, r);
}

TEST(tk, throw_when_0_set) {
  vector< pair< int, int > > p2;
  ASSERT_ANY_THROW(tk(p2, 0));
}
