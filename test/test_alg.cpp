#include <gtest/gtest.h>
#include "Algs.h"
#include <vector>
#include <iostream>

using std::vector;
using std::pair;

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

TEST(algPrim, throw_with_0_vector) {
  vector < vector<int> > b;

  ASSERT_ANY_THROW(Prim(LS_to_graph(b)));
}

TEST(algKruskal, throw_with_0_vector) {
  vector < vector<int> > b;
  ASSERT_ANY_THROW(Kruskal(MI_to_graph(b)));
}

TEST(algKruskal, work_with_cycle_graph) {
  vector < vector<int> > b = { {1, 1, 0, 0}, {0, 2, 2, 0},
    {0, 0, 3, 3}, {4, 0, 0, 4} };

  auto a = Kruskal(MI_to_graph(b));

  vector< edge > m;
  m.push_back(edge(0, 1));
  m.push_back(edge(1, 2));
  m.push_back(edge(2, 3));


  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(m[i].f, a[i].f);
    EXPECT_EQ(m[i].s, a[i].s);
  }
}

TEST(algPrim, work_with_cycle_graph) {
  vector < vector<int> > b = { { 0, 1, 1 }, { 1, 2, 2 },
    { 2, 3, 3 }, { 3, 0, 4 } };

  auto a = Prim(LS_to_graph(b));

  vector< edge > m;
  m.push_back(edge(0, 1));
  m.push_back(edge(3, 0));
  m.push_back(edge(1, 2));


  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(m[i].f, a[i].f);
    EXPECT_EQ(m[i].s, a[i].s);
  }
}

TEST(algKruskal, graph1) {
  vector < vector<int> > b = { { 1, 1, 0, 0 }, { 0, 2, 2, 0 },
    { 0, 0, 3, 3 }, { 4, 0, 0, 4 } };

  auto a = Kruskal(MI_to_graph(b));

  vector< edge > m;
  m.push_back(edge(0, 1));
  m.push_back(edge(1, 2));
  m.push_back(edge(2, 3));

  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(m[i].f, a[i].f);
    EXPECT_EQ(m[i].s, a[i].s);
  }
}

TEST(algKruskal, work_with_graph2) {
  vector < vector<int> > b = { { 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 2, 2, 0, 0, 0, 0, 0 }, { 0, 0, 3, 3, 0, 0, 0, 0 },
  { 4, 0, 0, 4, 0, 0, 0, 0 }, { 0, 0, 2, 0, 0, 2, 0, 0 },
  { 0, 0, 0, 0, 0, 3, 0, 3 }, { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 8, 8, 0, 0 }, { 0, 3, 0, 0, 0, 0, 0, 3 },
  { 0, 0, 0, 0, 4, 0, 4, 0 }, { 1, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 3, 0, 0, 3 } };

  auto a = Kruskal(MI_to_graph(b));

  ASSERT_ANY_THROW(Kruskal(MI_to_graph(b)));
}
